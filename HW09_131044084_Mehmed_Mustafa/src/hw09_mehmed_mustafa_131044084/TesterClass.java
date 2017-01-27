package hw09_mehmed_mustafa_131044084;

public class TesterClass {
    
    public static void main(String[] args)
    {
        System.out.println("----------START TEST FOR INDEPENDANCY----------");
        
        double[] mArr = {5.0, 2.5, 3.0};       
        PolynomialClass M = new PolynomialClass(mArr);
        // M polynomial now is = 3.0x^2 + 2.5x + 5.0
        
        M.setNcoef(2, 5.7);
        // M polynomial now is = 5.7x^2 + 2.5x + 5.0
        
        System.out.println("mArr[0]: " + mArr[0]);
        System.out.println("mArr[1]: " + mArr[1]);
        System.out.println("mArr[2]: " + mArr[2]);
        System.out.println();
        // Last 4 lines print 5.0, 2.5, 3.0
        // This shows that we've made independent copy(clone) with constructor
        
        double[] mArr2 = M.getCoefficients();
        // mArr2 = {5.0, 2.5, 5.7}
        
        M.setNcoef(1, 4.7);
        // M polynomial now is = 5.7x^2 + 4.7x + 5.0
        
        System.out.println("mArr2[0]: " + mArr2[0]);
        System.out.println("mArr2[1]: " + mArr2[1]);
        System.out.println("mArr2[2]: " + mArr2[2]);
        // Last 4 lines print 5.0, 2.5, 5.7
        // This shows that we've made independent copy(clone) with getCoefficients()
        
        System.out.println("----------END TEST FOR INDEPENDANCY------------");       
        System.out.println();
        
        double[] nArr = {5.0, 2.5, 3.0};
        PolynomialClass N = new PolynomialClass(nArr);
        // M polynomial is = 3.0x^2 + 2.5x + 5.0
        double evaluated = N.evaluatePolynomial(2.5);
        // Evaluate the value of the polynomial M for x = 2.5
        N.toString();
        System.out.println("The value of the polynomial for x = 2.5 is: " + evaluated);
        evaluated = N.evaluatePolynomial(3.0);
        // Evaluate the value of the polynomial M for x = 3.0
        N.toString();
        System.out.println("The value of the polynomial for x = 3.0 is: " + evaluated);        
        evaluated = N.evaluatePolynomial(-0.5);
        // Evaluate the value of the polynomial M for x = -0.5
        N.toString();
        System.out.println("The value of the polynomial for x = -0.5 is: " + evaluated);
        System.out.println();
        
        System.out.println("----------TEST FOR ADDITION, SUBSTRACTION----------");
        // Any value can be given to A and B arrays for testing
        double[] a = {4.2, 3.5, 5.1, 6.2, -1.5};
        double[] b = {1.0, -3.7, 2.3, 1.3};
        
        // -1.5x^4 + 6.2x^3 + 5.1x^2 + 3.5x + 4.2
        PolynomialClass A = new PolynomialClass(a);
        // 1.3x^3 + 2.3x^2 - 3.7x + 1.0
        PolynomialClass B = new PolynomialClass(b);
        
        System.out.print("First polynomial: ");
        A.toString();
        System.out.print("Second polynomial: ");
        B.toString();
        PolynomialClass C = new PolynomialClass((A.addPolynomial(B)).getCoefficients());
        System.out.print("The result of addition: ");
        C.toString();
        System.out.println();
        
        System.out.print("First polynomial: ");
        A.toString();
        System.out.print("Second polynomial: ");
        B.toString();        
        PolynomialClass D = new PolynomialClass((A.subPolynomial(B)).getCoefficients());
        System.out.print("The result of substraction: ");
        D.toString();       
        System.out.println("----------END TEST FOR ADDITION, SUBSTRACTION--------");
        System.out.println(); System.out.println();
        
        System.out.println("----------TEST FOR MULTIPLICATION--------------");
        System.out.print("First polynomial: ");
        A.toString();
        System.out.print("Second polynomial: ");
        B.toString();        
        PolynomialClass E = new PolynomialClass((A.mulPolynomial(B)).getCoefficients());
        System.out.print("The result of multiplication: ");
        E.toString();
        System.out.println("----------END TEST FOR MULTIPLICATION----------");
    }
    
}
