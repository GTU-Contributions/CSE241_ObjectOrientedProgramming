package hw09_mehmed_mustafa_131044084;

/**
 * Java class example
 * The class that represents a polynomial
 * 
 *
 * @author Mehmed Mustafa [131044084]
 * @version 1.00, 23 Dec 2015
 */
public class PolynomialClass
{
    // Double array to store coefficients of the polynomial
    private double[] coefficients;
    private final int numOfcoef; // Number of coefficients
    
    /** 
     *  The polynomial is set to 1.0x + 0.0,
     *  The numOfcoef is set to 1
     */
    public PolynomialClass(){
        double[] defaultArray = {0.0, 1.0};
        coefficients = defaultArray;
        numOfcoef = coefficients.length;
    }
    
    /** 
     *  The numOfcoef is set to valNum
     *  @param valNum number of coefficients for the polynomial
     */
    public PolynomialClass(int valNum){
        numOfcoef = valNum;
        coefficients = new double[numOfcoef];
    }
    
    /** 
     *  Initialize coefficients to arr
     *  @param arr double array that contains coefficients
     */
    public PolynomialClass(final double[] arr){
        coefficients = arr.clone();
        numOfcoef = coefficients.length;
    }

    /**
     * Sets independent copy(clone) of arr to coefficients
     * @param arr double array that contains coefficients
     */
    public void setCoefficients(final double[] arr){
        coefficients = arr.clone();
    }
    
    /**
     * Sets coefVal to the position of the given degree
     * @param degree position where the coefVal will be placed
     * @param coefVal value which will be placed at degree position
     */
    public void setNcoef(int degree, double coefVal){
        coefficients[degree] = coefVal;
    }
   
    /**
     * Returns the coefficients clone of the object
     * @return coefficients clone
     */
    public double[] getCoefficients(){
        return coefficients.clone();
    }
    
    /**
     * Returns the coefficient at the degree position
     * @param degree position from which we get the coefficient value
     * @return coefficients[degree]
     */
    public double getNcoef(int degree){
        return coefficients[degree];
    }
    
    /**
     * Evaluate the polynomial
     * @param valX value for which the polynomial is evaluated
     * @return The result from the evaluation of the polynomial
     */
    public double evaluatePolynomial(double valX){
        double result = 0.0;
        
        for(int i=0; i<coefficients.length; ++i)
            result += coefficients[i]*(Math.pow(valX,i));
        
        return result;
    }
    
    /**
     * Returns the number of coefficients
     * @return the number of the coefficients in the polynomial
     */
    public int getNumberOfterms(){
        return coefficients.length;
    }
    
    /**
     * Addition of the polynomials
     * @param other takes other polynomial to add to current polynomial
     * @return result from addition of the polynomials
     */
    public PolynomialClass addPolynomial(final PolynomialClass other){
           int size; // Size of the bigger polynomial
           
           // Size of the first poly, this object
           int thisPoly = getNumberOfterms();
           // Size of the second poly, parameter object
           int otherPoly = other.getNumberOfterms(); 
           
           //Take the size of the bigger polynomial
           if(thisPoly > otherPoly)
               size = thisPoly; // If the first polynomial is bigger
           else // If the polynomial as a parameter is bigger
               size = otherPoly;
           
           double[] addResult = new double[size];
           
           if(thisPoly > otherPoly) // If this poly's size is bigger
           {
               for(int i=thisPoly-1; i>otherPoly-1; --i)
                   addResult[i] = coefficients[i];
               for(int i=otherPoly-1; i>=0; --i)
                   addResult[i] = coefficients[i] + other.coefficients[i];
           }
           else if(thisPoly < otherPoly) // If other poly's size is bigger
           {
               for(int i=otherPoly-1; i>thisPoly-1; --i)
                   addResult[i] = other.coefficients[i];
               for(int i=thisPoly-1; i>=0; --i)
                   addResult[i] = coefficients[i] + other.coefficients[i];               
           }
           else // If thisPoly == otherPoly - If the sizes are equal
           {
               for(int i=thisPoly-1; i>=0; --i)
                   addResult[i] = coefficients[i] + other.coefficients[i];                
           }
           
           // Result of addition of the polynomials
           PolynomialClass result = new PolynomialClass(addResult);
           return result;
    }
    
    /**
     * Substraction of the polynomials
     * @param other takes other polynomial to substract from current polynomial
     * @return result from substraction of the polynomials
     */
    public PolynomialClass subPolynomial(final PolynomialClass other){
           int size; // Size of the bigger polynomial
           
           // Size of the first poly, this object
           int thisPoly = getNumberOfterms();
           // Size of the second poly, parameter object
           int otherPoly = other.getNumberOfterms(); 
           
           //Take the size of the bigger polynomial
           if(thisPoly > otherPoly)
               size = thisPoly; // If the first polynomial is bigger
           else // If the polynomial as a parameter is bigger
               size = otherPoly;
           
           double[] subResult = new double[size];
           
           //
           if(thisPoly > otherPoly) // If this poly's size is bigger
           {
               for(int i=thisPoly-1; i>otherPoly-1; --i)
                   subResult[i] = coefficients[i];
               for(int i=otherPoly-1; i>=0; --i)
                   subResult[i] = coefficients[i] - other.coefficients[i];
           }
           else if(thisPoly < otherPoly) // If other poly's size is bigger
           {
               for(int i=otherPoly-1; i>thisPoly-1; --i)
                   subResult[i] = -other.coefficients[i];
               for(int i=thisPoly-1; i>=0; --i)
                   subResult[i] = coefficients[i] - other.coefficients[i];               
           }
           else // If thisPoly == otherPoly - If the sizes are equal
           {
               for(int i=thisPoly-1; i>=0; --i)
                   subResult[i] = coefficients[i] - other.coefficients[i];                
           }
           
           // Result of substraction of the polynomials
           PolynomialClass result = new PolynomialClass(subResult);
           return result;            
    } 
    
    /**
     * Multiplication of the polynomials
     * @param other takes other polynomial to multiply with current polynomial
     * @return result from multiplication of the polynomials
     */
    public PolynomialClass mulPolynomial(final PolynomialClass other){
        // Size of the first poly, this object
        int thisPoly = getNumberOfterms();
        // Size of the second poly, parameter object
        int otherPoly = other.getNumberOfterms(); 
           
        int resultSize = thisPoly + otherPoly;
        
        double[] mulResult = new double[resultSize-1];
        
        for (int i = thisPoly-1; i >= 0; --i)
            for (int j = otherPoly-1; j >= 0; --j)        
                mulResult[i+j] = 0;
                
        for (int i = thisPoly-1; i >= 0; --i)
            for (int j = otherPoly-1; j >= 0; --j)
                mulResult[i+j] += coefficients[i] * other.coefficients[j];
        
        // Result of multiplication of the polynomials
        PolynomialClass result = new PolynomialClass(mulResult);
        return result;        
    }
    
    /**
     * @return polynomial in string format
     */
    @Override
    public String toString(){
        String result;
        
        String temp = String.format("%.2f", coefficients[getNumberOfterms()-1]);
        result = temp + "x^" + (getNumberOfterms()-1) + " ";
        for(int i=getNumberOfterms()-2; i>=0; --i)
        {
            if(coefficients[i] > 0.0)
            {
                temp = String.format("%.2f", coefficients[i]);
                result += " + " + temp + "x^" + i + " ";
            }
            else if(coefficients[i] < 0.0)
            {
                temp = String.format("%.2f", -coefficients[i]);
                result += " - " + temp + "x^" + i + " ";
            }
        }

        System.out.println(result);
        return String.format("%s", result);
    }
    
    @Override
    public int hashCode(){
        return getNumberOfterms();
    }
    
    /**
     * 
     * @param other takes other polynomial to compare with current polynomial
     * @return true if the polynomial is same as object
     */
    @Override
    public boolean equals(Object other){
        if (other == this) 
            return true;
        if (other == null || !(other instanceof PolynomialClass))
            return false;
        
        PolynomialClass temp = (PolynomialClass)other;
        
        return getCoefficients() == temp.getCoefficients();
    }
    
}