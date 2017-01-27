package hw10_mehmed_mustafa_131044084;

import static hw10_mehmed_mustafa_131044084.Operator.isOperator;
import static hw10_mehmed_mustafa_131044084.Parentheses.findFirstClosingParenthese;
import static hw10_mehmed_mustafa_131044084.Parentheses.findFirstOpeningParenthese;
import static hw10_mehmed_mustafa_131044084.Parentheses.isCloseParentheses;
import static hw10_mehmed_mustafa_131044084.Parentheses.isOpenParentheses;
import static hw10_mehmed_mustafa_131044084.Parentheses.isParentheses;
import static hw10_mehmed_mustafa_131044084.Parentheses.validateParentheses;
import static java.lang.System.exit;
import java.util.ArrayList;
import static jdk.nashorn.internal.runtime.JSType.isNumber;

/**
 *
 * @author Mehmed Mustafa [131044084]
 * @version 1.00, 03 Jan 2016
 */
public class Expression
{
    private final ArrayList<Expression> expression;
    
    /**
     * Makes new object with initialized new arrayList
     */
    public Expression()
    {
        this.expression = new ArrayList();
    }
    
    /**
     * Sets expression to exp object
     * @param exp Expression object
     */
    public Expression(Expression exp)
    {
        this.expression = exp.expression;
    }
    
    /**
     * Sets expression to exp list
     * @param exp Expression list
     */
    public Expression(ArrayList<Expression> exp)
    {
        this.expression = exp;
    }
    
    /**
     * 
     * @return expression
     */
    public ArrayList<Expression> getExpression()
    {
        return expression;
    }
    
    // Setter is not needed
    
    /**
     * Sets s to the end of the expression
     * @param s input string
     */
    public void addElement(String s)
    {
        if(isNumber(s)){
           Operand temp = new Operand(s, Integer.parseInt(s));
           expression.add(temp);
        }
        else if(isOperator(s)){
           Operator temp = new Operator(s);
           expression.add(temp);                
        }
        else if(isParentheses(s)){
           Parentheses temp = new Parentheses(s);
           expression.add(temp);                 
        }
    }
    
    /**
     * 
     * @return size of the expression
     */
    public int getSize()
    {
        return expression.size();
    }
    
    /**
     * Checks if the expression is valid
     * @return true if the expression is valid
     */
    public boolean isValidExpression()
    {
        // Check the first element of the expression
        // If the first element is an operator
        if(expression.get(0) instanceof Operator)
        {
            System.out.println("Expression can't start with operator!!");
            return false;
        }
        
        // If the first element is a parenthese
        if(expression.get(0) instanceof Parentheses)
        {
            String s = expression.get(0).toString();
            // If we have closing parenthese
            if(isCloseParentheses(s)) 
            {
                System.out.println("Expression can't start with closing parenthese!");
                return false;
            }
        }
        // Check from second to the element before the last one
        for(int i = 1; i < expression.size()-1; ++i)
        {
            // If the current element is a parenthese
            if(expression.get(i) instanceof Parentheses)
            {
                String curElm = expression.get(i).toString();
                // If the current element is an opening parenthese
                if(isOpenParentheses(curElm))
                {
                    // Check the left side
                    // If the left element is a parenthese
                    if(expression.get(i-1) instanceof Parentheses)
                    {
                        String leftElm = expression.get(i-1).toString();
                        //If the left element is closing parenthese
                        if(isCloseParentheses(leftElm)){
                            System.out.print("Expression can't have opening parenthese");
                            System.out.println(" after closing parentheses!");
                            System.out.println("Position of the error: " + i);
                            return false;
                        }
                    }
                    // If the left element is an operand
                    if(expression.get(i-1) instanceof Operand){
                        System.out.print("Expression can't have opening parenthese");
                        System.out.println(" after operand!");
                        System.out.println("Position of the error: " + i);
                        return false;
                    }
                }
                // Else, the current element is a closing parenthese
                else
                {
                    // Check the left side
                    // If the left element is a parenthese
                    if(expression.get(i-1) instanceof Parentheses)
                    {
                        String leftElm = expression.get(i-1).toString();
                        //If the left element is an opening parenthese
                        if(isOpenParentheses(leftElm))
                        {
                            System.out.println("No expression between parentheses!");
                            System.out.println("Position of the error: " + i);
                            return false;
                        }
                    }
                    // If the left element is an operator
                    if(expression.get(i-1) instanceof Operator)
                    {
                        System.out.print("Expression can't have closing parenthese");
                        System.out.println(" after operator!");
                        System.out.println("Position of the error: " + i);
                        return false;
                    }
                }
            }
            // If the current element is an Operator
            if(expression.get(i) instanceof Operator)
            {
                // Check the left side
                // If the left element is a parenthese
                if(expression.get(i-1) instanceof Parentheses)
                {
                    String leftElm = expression.get(i-1).toString();
                    //If the left element is an opening parenthese
                    if(isOpenParentheses(leftElm))
                    {
                        System.out.print("Expression can't have operator");
                        System.out.println(" after opening parenthese!");
                        System.out.println("Position of the error: " + i);
                        return false;
                    }
                }
                // If the left element is an operator
                if(expression.get(i-1) instanceof Operator)
                {
                    System.out.print("Expression can't have operator");
                    System.out.println(" after operator!");
                    System.out.println("Position of the error: " + i);
                    return false;
                }

            }
            // If the current element is an Operand
            if(expression.get(i) instanceof Operand)
            {
                // Check the left side
                // If the left element is a parenthese
                if(expression.get(i-1) instanceof Parentheses)
                {
                    String leftElm = expression.get(i-1).toString();
                    //If the left element is a closing parenthese
                    if(isCloseParentheses(leftElm))
                    {
                        System.out.print("Expression can't have operand");
                        System.out.println(" after closing parenthese!");
                        System.out.println("Position of the error: " + i);
                        return false;
                    }
                }
                // If the left element is an operand
                if(expression.get(i-1) instanceof Operand)
                {
                    System.out.print("Expression can't have operand");
                    System.out.println(" after operand!");
                    System.out.println("Position of the error: " + i);
                    return false;
                }                
            }             
        }
        
        // Check the last element of the expression
        // If the last element is an operator
        if(expression.get(expression.size()-1) instanceof Operator)
        {
            System.out.println("Expression can't end with operator!!");
            return false;
        }
        // If the last element is an operand
        if(expression.get(expression.size()-1) instanceof Operand)
        {
            // If the element before last element is not an operator
            if(!(expression.get(expression.size()-2) instanceof Operator))
            {
                System.out.print("Expression can't end with operand");
                System.out.println(" if no operator is before the operand!");
                return false;
            }
        }
        // If the last element is a parenthese
        if(expression.get(expression.size()-1) instanceof Parentheses)
        {
            String s = expression.get(expression.size()-1).toString();
            // If the last element is an opening parenthese
            if(isOpenParentheses(s))
            {
                System.out.println("Expression can't end with opening parenthese!!");
                return false;
            }
            else // we have closing parenthese
            {
                // If the element before last element is a parenthese
                if(expression.get(expression.size()-2) instanceof Parentheses)
                {
                    String s2 = expression.get(expression.size()-2).toString();
                    // If the element before last element is an opening parenthese
                    if(isOpenParentheses(s2))
                    { 
                        System.out.println("No expression between parentheses!");
                        return false;
                    }
                }
                // If the element before last element is an operator
                if(expression.get(expression.size()-2) instanceof Operator)
                {
                    System.out.print("Expression can't have closing parenthese");
                    System.out.println(" after operator!");
                    return false;                    
                }
            }
        }
        
        // If there isn't closing parenthese for every open parenthese
        if(!validateParentheses(expression))
        {
            System.out.println("The number of opening and closing parentheses aren't equal!");
            return false;
        }
        
        return true;
    }
    
    /**
     * Evaluate for one operator
     * @param op operator
     * @param op1 first operand
     * @param op2 second operand
     * @return result of the operator on operand1 and operand2
     */
    public static Operand evaluateOneStep(Operator op, Operand op1, Operand op2)
    {
        int result = 0;
        
        switch(op.getOperator())
        {
            case "+":
                result = op1.getValue() + op2.getValue();
                break;
            case "-":
                result = op1.getValue() - op2.getValue();
                break;
            case "*":
                result = op1.getValue() * op2.getValue();
                break;
            case "/":
                // EXCEPTION NOT NECESSARY
                if(op2.getValue() == 0)
                {
                    System.out.println("ERROR! Dividing to 0 in the expression!");
                    System.out.println("Terminating the program!");
                    exit(1);
                }
                result = op1.getValue() / op2.getValue();
                break;
            default:
                System.out.println("ERROR IN OPERATOR in evaluateOneStep function!");
                break;
        }
        
        Operand temp = new Operand(result);
        
        return temp;
    }
    
    /**
     * Simplify expression by one step
     * @param exp expression list
     * @return simplified by one step expression list
     */
    public static ArrayList<Expression> simplifyExpression(ArrayList<Expression> exp)
    {
        // If the expression is only 1 operand, return the same expression
        if(exp.size() == 1)
        {
            return exp;
        }
        
        // Find the index of the first closing parenthese
        int indexEnd = findFirstClosingParenthese(exp);
        // Find the index of the first opening parenthese 
        // Starting from indexEnd and going backward
        int indexStart = findFirstOpeningParenthese(exp, indexEnd);
        
        // If we have parentheses in the expression
        if(indexEnd != -1 && indexStart != -1)
        {
            // If we have only one element between the parentheses
            if(indexStart == indexEnd-2)
            {
                // Save the operand between parentheses
                Operand tempOperand = (Operand)exp.get(indexStart+1);
                // Clear the parentheses and the element
                exp.subList(indexStart, indexEnd).clear();
                // Add the element to the place of the opening parenthese
                exp.set(indexStart, tempOperand);
                // Return new array list
                return exp;
            }
            
            // Check all elements between the parentheses for High Priority Operators
            for(int i = indexStart; i < indexEnd; ++i)
            {
                // If we find operator
                if(exp.get(i) instanceof Operator)
                {
                    Operator tempOp = (Operator)exp.get(i);
                    // If the operator is * or /
                    if(tempOp.getPriority())
                    {
                        Operand op1 = (Operand)exp.get(i-1); // Cast first operand
                        Operand op2 = (Operand)exp.get(i+1); // Cast second operand
                        // Evaluate and get the result
                        Operand result = evaluateOneStep(tempOp, op1, op2);
                        // Clear the operator and operands
                        exp.subList(i-1, i+1).clear();
                        // Add the result to the place of the first operand
                        exp.set(i-1, result);
                        // Return new array list
                        return exp;                       
                    }
                }
            }
            
            // Check all elements between the parentheses for Low Priority Operators
            for(int i = indexStart; i < indexEnd; ++i)
            {
               // If we find operator
                if(exp.get(i) instanceof Operator)
                {
                    Operator tempOp = (Operator)exp.get(i);
                    // If the operator is + or -
                    if(!tempOp.getPriority())
                    {
                        Operand op1 = (Operand)exp.get(i-1); // Cast first operand
                        Operand op2 = (Operand)exp.get(i+1); // Cast second operand
                        // Evaluate and get the result
                        Operand result = evaluateOneStep(tempOp, op1, op2);
                        // Clear the operator and operands
                        exp.subList(i-1, i+1).clear();
                        // Add the result to the place of the first operand
                        exp.set(i-1, result);
                        // Return new array list
                        return exp;                        
                    }
                }
            }
        }
        else // No parentheses in the expression
        {
            // Check all elements in the expression for High Priority Operators
            for(int i = 0; i < exp.size(); ++i)
            {
                // If we find operator
                if(exp.get(i) instanceof Operator)
                {
                    Operator tempOp = (Operator)exp.get(i);
                    // If the operator is * or /
                    if(tempOp.getPriority())
                    {
                        Operand op1 = (Operand)exp.get(i-1); // Cast first operand
                        Operand op2 = (Operand)exp.get(i+1); // Cast second operand
                        // Evaluate and get the result
                        Operand result = evaluateOneStep(tempOp, op1, op2);
                        // Clear the operator and operands
                        exp.subList(i-1, i+1).clear();
                        // Add the result to the place of the first operand
                        exp.set(i-1, result);
                        // Return new array list
                        return exp;                       
                    }
                }
            }
            
            // Check all elements in the expression for Low Priority Operators
            for(int i = 0; i < exp.size(); ++i)
            {
               // If we find operator
                if(exp.get(i) instanceof Operator)
                {
                    Operator tempOp = (Operator)exp.get(i);
                    // If the operator is + or -
                    if(!tempOp.getPriority())
                    {
                        Operand op1 = (Operand)exp.get(i-1); // Cast first operand
                        Operand op2 = (Operand)exp.get(i+1); // Cast second operand
                        // Evaluate and get the result
                        Operand result = evaluateOneStep(tempOp, op1, op2);
                        // Clear the operator and operands
                        exp.subList(i-1, i+1).clear();
                        // Add the result to the place of the first operand
                        exp.set(i-1, result);
                        // Return new array list
                        return exp;                        
                    }
                }
            }            
        }
        
        return exp;
    }

    /**
     * 
     * @return Expression in string format
     */
    @Override
    public String toString()
    {
        String result = "";
        
        for (int i = 0; i < expression.size(); ++i){
            result += expression.get(i);
        }
        
        return result;
    }
    
    /**
     * 
     * @param other other Object to compare
     * @return true if the expression is same as object other
     */
    @Override
    public boolean equals(Object other)
    {
        if (other == this) 
            return true;
        if (other == null || !(other instanceof Expression))
            return false;
        
        Expression temp = (Expression)other;
        
        return getExpression() == temp.getExpression();        

    }

    // AUTOMATICALLY GENERATED HASH CODE
    @Override
    public int hashCode() {
        int hash = 5;
        return hash;
    }
}
