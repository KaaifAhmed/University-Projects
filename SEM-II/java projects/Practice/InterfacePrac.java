interface Shape {
    double getArea ();
    double getPerimeter ();
}

class Circle implements Shape {
    double r;
    private final double PI = 3.142;

    Circle (double r) {
        this.r = r;
    }

    @Override
    public double getArea () {
        return PI * r * r;
    }

    @Override
    public double getPerimeter () {
        return 2 * PI * r;
    }
}

class Rectangle implements Shape {
    double l;
    double b;
    private final double PI = 3.142;

    Rectangle (double l, double b) {
        this.l = l;
        this.b = b;
    }

    @Override
    public double getArea () {
        return l*b;
    }

    @Override
    public double getPerimeter () {
        return l+b;
    }
}

public class InterfacePrac {
    public static void main(String[] args) {
        Shape myCuteCirc = new Circle(2);
        Shape myCuteRect = new Rectangle(2, 3);

        System.out.println(shapeArea(myCuteCirc));
        System.out.println(shapeArea(myCuteRect));
        
    }
    
    public static double shapeArea (Shape shape) {
        return shape.getArea();
    }
}
