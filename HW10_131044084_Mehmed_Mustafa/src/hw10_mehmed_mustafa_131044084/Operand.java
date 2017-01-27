package hw10_mehmed_mustafa_131044084;

/**
 *
 * @author Mehmed Mustafa [131044084]
 * @version 1.00, 03 Jan 2016
 */
public class Operand extends Expression
{
    private final String variable;
    private final int value;
    
    /** 
     *  The variable is set to "0"
     *  The value is set to 0
     */
    public Operand()
    {
        this.variable = "0";
        this.value = 0;
    }

    /** 
     *  The variable is set to string format of value
     *  The value is set to value
     * @param value value of the operand
     */
    public Operand(int value)
    {
        this.variable = Integer.toString(value);
        this.value = value;
    }
    
    /**
     * The variable is set to variable
     * The value is set to integer format of value
     * @param variable string format operand
     */
    public Operand(String variable)
    {
        this.variable = variable;
        this.value = Integer.parseInt(variable);
    }
    
    /**
     * The variable is set to variable
     * The value is set to value
     * @param variable string format operand
     * @param value value of the operand
     */   
    public Operand(String variable, int value)
    {
        this.variable = variable;
        this.value = value;
    }
    
    /**
     * 
     * @return value
     */
    public int getValue(){
        return value;
    }

    /**
     * @return operator in string format
     */
    @Override
    public String toString()
    {
        return variable;
    }   
   
}
