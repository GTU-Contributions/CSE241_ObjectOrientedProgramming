package hw10_mehmed_mustafa_131044084;

/**
 *
 * @author Mehmed Mustafa [131044084]
 * @version 1.00, 03 Jan 2016
 */
public class Operator extends Expression
{
    
    private final String operator;
    // True for * and /
    // False for + and -
    private final boolean hasPriority;
    
    /** 
     *  The operator is set to +
     *  hasPriority is set to false
     */
    public Operator()
    {
        this.operator = "+";
        this.hasPriority = false;
    }

    /** 
     *  The operator to op
     * @param op operator
     */
    public Operator(String op)
    {
        this.operator = op;
        if(operator.equals("*") || operator.equals("/"))
            this.hasPriority = true;
        else
            this.hasPriority = false;
    }
    
     /**
     * Checks if the s is operator
     * @param s input string
     * @return true if the s is operator
     */    
    public static boolean isOperator(String s)
    {
        return(s.equals("*") || s.equals("/") || s.equals("+") || s.equals("-"));
    }   
    
    /**
     * 
     * @return operator
     */
    public final String getOperator()
    {
        return operator;
    }
        
    /**
     * 
     * @return priority
     */
    public boolean getPriority()
    {
        return hasPriority;
    }
    
    // Setter is not needed

    /**
     * @return operator in string format
     */    
    @Override
    public String toString()
    {
        return operator;
    }
    
}
