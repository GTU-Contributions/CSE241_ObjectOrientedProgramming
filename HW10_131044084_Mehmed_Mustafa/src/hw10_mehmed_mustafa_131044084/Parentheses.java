package hw10_mehmed_mustafa_131044084;

import java.util.ArrayList;
import java.util.Stack;

/**
 *
 * @author Mehmed Mustafa [131044084]
 * @version 1.00, 03 Jan 2016
 */
public class Parentheses extends Expression
{  
    private final String parentheses;
    
    /** 
     *  The parentheses is set to open ("(")
     */
    public Parentheses()
    {
        this.parentheses = "(";
    }
    
    /** 
     *  The parentheses is set to s
     * @param s input string
     */      
    public Parentheses(String s)
    {
        this.parentheses = s;
    }
    
    /**
     * Returns the parenthese symbol
     * @return the parenthese symbol
     */
    public String getParentheses()
    {
        return parentheses;
    }
    
    // Setter is not needed
    
     /**
     * Checks if the s is parenthese
     * @param s input string
     * @return true if the s is parenthese
     */
    public static boolean isParentheses(String s)
    {
        return(s.equals("(") || s.equals(")"));
    }
    
     /**
     * Checks if the s is opening parenthese
     * @param s input string
     * @return true if the s is opening parenthese
     */
    public static boolean isOpenParentheses(String s)
    {
        return(s.equals("("));
    }
    
    /**
     * Checks if the s is closing parenthese
     * @param s input string
     * @return true if the s is closing parenthese
     */
    public static boolean isCloseParentheses(String s)
    {
        return(s.equals(")"));
    }
    
     /**
     * Checks if two parentheses match
     * @param opened first parameter should be for opening parenthese
     * @param closed second parameter should be for closing parenthese
     * @return true if the opened is open and closed is close parenthese
     */
    public static boolean matchingParentheses(String opened, String closed)
    {
        return(opened.equals("(") && closed.equals(")"));
    }
    
    /**
     * Finds the index of the first closing parenthese in the list
     * @param list expression list
     * @return the index of the first closing parenthese
     */
    public static int findFirstClosingParenthese(ArrayList<Expression> list)
    {       
        // Check all elements in the array list
        for(int i = 0; i < list.size(); ++i)
        {
            // If the element is a parenthese
            if(list.get(i) instanceof Parentheses)
            {   
                String s = list.get(i).toString();
                // If the element is closing parenthese
                if(isCloseParentheses(s))
                    return i; // Get the index of that element
            }            
        }
        
        return -1; // When a closing parenthese is not found, return -1
    }
    
    /**
     * Finds the index of the first opening parenthese in the list going backward from start
     * @param list expression list
     * @param start starting position
     * @return the index of the first opening parenthese in the list going backward from start
     */    
    public static int findFirstOpeningParenthese(ArrayList<Expression> list, int start)
    {
        if(start == -1) // If the coming start position isn't valid
            return -1; // no opening parenthese is found
        
        for(int i = start; start >= 0; --i)
        {
            // If the element is a parenthese
            if(list.get(i) instanceof Parentheses)
            {   
                String s = list.get(i).toString();
                // If the element is opening parenthese
                if(isOpenParentheses(s))
                    return i; // Get the index of that element
            }
        }
        
        return -1; // When a opening parenthese isn't found, return -1
    }
    
    /** 
     *  Validate parentheses
     * @param expression expression list
     * @return true if the parentheses are valid
     */    
    public static boolean validateParentheses(ArrayList<Expression> expression)
    {
        Stack s = new Stack();
        String currentParenthese;
        String previousParenthese;
        boolean isValid = true;
        
        // Check all elements in the expression
        for(int i = 0; i < expression.size(); ++i)
        {
            // If we find parentheses element
            if(expression.get(i) instanceof Parentheses)
            {
                Parentheses tempPar = (Parentheses)expression.get(i);
                currentParenthese = tempPar.getParentheses();
                // If the current element is opening parenthese
                if(isOpenParentheses(currentParenthese))
                {
                    // push "("
                    s.push(currentParenthese);
                }
                // If the current element is closing parenthese
                else if(isCloseParentheses(currentParenthese))
                {
                    // If the stack isn't containing any opening parenthese
                    if(s.isEmpty())
                    {
                        isValid = false;
                        break;
                    }
                    else // There are elements in the stack
                    {
                        // Get the last element of the stack
                        // It should be "("
                        previousParenthese = (String)s.pop();
                        // Check if the parentheses match
                        if(!matchingParentheses(previousParenthese, currentParenthese))
                        { // If they don't
                            isValid = false;
                            break;
                        }
                    }
                    
                }
                
            }
        }
        
        // If there is any elements in the stack remaining
        if(!s.isEmpty())
            isValid = false;
        
        return isValid;
    }

    /**
     * @return parenthese in string format
     */    
    @Override
    public String toString(){
        return parentheses;
    }    
    
}