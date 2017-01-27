package hw10_mehmed_mustafa_131044084;

import static hw10_mehmed_mustafa_131044084.Expression.simplifyExpression;
import static hw10_mehmed_mustafa_131044084.Operator.isOperator;
import static hw10_mehmed_mustafa_131044084.Parentheses.isParentheses;
import static jdk.nashorn.internal.runtime.JSType.isNumber;
import static java.lang.System.exit;
import java.util.Scanner;

/**
 *
 * @author Mehmed Mustafa [131044084]
 * @version 1.00, 03 Jan 2016
 */
public class TestClass {
    public static void main(String[] args){        
        System.out.print("Enter your expression, after each operator or ");
        System.out.println("operand press enter, to end the expression press =");       
        
        Expression exp = new Expression();
        
        Scanner input = new Scanner(System.in);
        String ch;
        
        // NO EXCEPTION IS NEEDED HERE, WORKS FINE FOR EVERY INPUT
        // WITH EXCEPTION THE PROGRAM WOULD WORK SLOWER
        while(true)
        {
            System.out.println("Enter your expression element");
            ch = input.nextLine();
            if(isNumber(ch) || isOperator(ch) || isParentheses(ch)){
                exp.addElement(ch);
            }
            else if(ch.equals("=")){
                break;
            }
            else{
                System.out.println("Wrong input, terminating the program!");
                exit(1);
            }
        }
        
        System.out.println(exp);
        
        if(!exp.isValidExpression()){
            System.out.println("The expression is not valid, terminating the program!");
            exit(1);
        }
        
        while(exp.getSize() > 1)
        {
            exp = new Expression(simplifyExpression(exp.getExpression()));

            System.out.println(exp);
        }
           
    }
    
}


