#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Menu Prototypes
int MainMenu();
int AreaMenu();
int VolumeMenu();
int PyramidMenu();
int PerimeterMenu();
int PolyhedronMenu();

// Perimeter Prototypes
double SquarePerimeter();
double CirclePerimeter();
double PolygonPerimeter();
double TrianglePerimeter();
double RectanglePerimeter();

// Volume Prototypes
double CubeVolume();
double ConeVolume();
double PrismVolume();
double SphereVolume();
double CylinderVolume();
double EllipsoidVolume();
double OctahedronVolume();
double TetrahedronVolume();
double IcosahedronVolume();
double DodecahedronVolume();
// this function uses a pass by ref parameter
const char *PyramidVolume(double *);

// Area of Polygons
void HexagonArea();
void OctagonArea();
void NonagonArea();
void DecagonArea();
void PentagonArea();
void HeptagonArea();
void TriangleArea();
void RectangleArea();

// Utility Prototype
int Converter();
double SideEntry();

// macro
// macro is used to define a constant value
// example: #define pi 3.14159
// pi is now a constant value of 3.14159, and you want to use it every time and don't need to change
// example: #define note() printf("\nPlease Select only from choices\n");
// note() is now a function that prints the string "Please Select only from choices" and you can use it every time
// note() is used in the main function
#define note() printf("\nPlease Select only from choices\n");

int main()
{
    double side;

    int menuChoice;
    double perimeter, volume, convert;
    char *perimeterSelectedName, *volumeSelectedName; // string holder

    float x, y, squared, angle;
    int shape;
    const double pi = 3.14159;
    char continue_choice;

    menuChoice = MainMenu();

    if (menuChoice == 1)
    {
        switch (PerimeterMenu())
        {
        case 0:
            return 0; // exit the program
        case 1:       // square
            perimeter = SquarePerimeter();
            perimeterSelectedName = "Square";
            break;
        case 2: // circle
            perimeter = CirclePerimeter();
            perimeterSelectedName = "Circle";
            break;
        case 3: // rectangle
            perimeter = RectanglePerimeter();
            perimeterSelectedName = "Rectangle";
            break;
        case 4: // triangle
            perimeter = TrianglePerimeter();
            perimeterSelectedName = "Triangle";
            break;
        case 5: // polygon
            perimeter = PolygonPerimeter();
            perimeterSelectedName = "Polygon";
            break;
        }

        printf("The total perimeter of the %s is : %.2lf", perimeterSelectedName, perimeter);
    }
    else if (menuChoice == 2)
    {
        switch (AreaMenu())
        {
        case 1:
            TriangleArea();
            break;

        case 2:
            RectangleArea();
            break;

        case 3:
            PentagonArea();
            break;

        case 4:
            HexagonArea();
            break;

        case 5:
            HeptagonArea();
            break;

        case 6:
            OctagonArea();
            break;

        case 7:
            NonagonArea();
            break;

        case 8:
            DecagonArea(x);
            break;

        default:
            printf("Invalid Polygon!");
            break;
        }
    }
    else if (menuChoice == 3)
    {
        switch (VolumeMenu())
        {
        case 0:
            return 0;
        case 1: // cube
            volume = CubeVolume();
            volumeSelectedName = "Cube";
            break;
        case 2: // prism
            volume = PrismVolume();
            volumeSelectedName = "Prism";
            break;
        case 3: // cylinder
            volume = CylinderVolume();
            volumeSelectedName = "Cylinder";
            break;
        case 4: // cone
            volume = ConeVolume();
            volumeSelectedName = "Cone";
            break;
        case 5: // sphere
            volume = SphereVolume();
            volumeSelectedName = "Sphere";
            break;
        case 6: // pyramids
            volumeSelectedName = PyramidVolume(&volume);
            break;

        case 7: // ellipsoid
            volume = EllipsoidVolume();
            volumeSelectedName = "Ellipsoid";
            break;

        case 8: // polyhedron
            switch (PolyhedronMenu())
            {
            case 1:
                volume = TetrahedronVolume();
                volumeSelectedName = "Tetrahedron";
                break;

            case 2:
                volume = OctahedronVolume();
                volumeSelectedName = "Octahedron";
                break;

            case 3:
                volume = DodecahedronVolume();
                volumeSelectedName = "Dodecahedron";
                break;

            case 4:
                volume = IcosahedronVolume();
                volumeSelectedName = "Icosahedron";
                break;

            default:
                printf("Invalid choice\n");
            }
        default:
            printf("Invalid choice\n");
            break;
        }

        printf("The total volume of the %s is: %.2lf\n", volumeSelectedName, volume);
    }
    else if (menuChoice == 5)
    {
        convert = Converter();
    }
    else if (menuChoice == 0)
        return 0;
    else
        printf("Invalid Choice");
    return 0;
}

// Menu Functions
int MainMenu()
{
    int required;

    do
    {
        note();
        printf("Choose what you want to get:\n");
        printf("1. Perimeter\n");
        printf("2. Area\n");
        printf("3. Volume\n");
        printf("4. All about circle\n");
        printf("5. Unit Converter\n");
        printf("0. Exit Program\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &required);
    } while (required < 0 || required > 5);

    return required;
}

int PerimeterMenu()
{
    int figureChoice;

    do
    {
        note();
        printf("What figure is it ?\n");
        printf("1. Square\n");
        printf("2. Circle\n");
        printf("3. Rectangle\n");
        printf("4. Triangle\n");
        printf("5. Polygon (up to Decagon)\n");
        printf("0. Exit Program\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &figureChoice);
    } while (figureChoice < 0 || figureChoice > 5);

    return figureChoice;
}

int VolumeMenu()
{
    int figureChoice;

    do
    {
        note();
        printf("What figure is it?\n");
        printf("1. Cube\n");
        printf("2. Prism\n");
        printf("3. Cylinder\n");
        printf("4. Cone\n");
        printf("5. Sphere\n");
        printf("6. Pyramid\n");
        printf("7. Ellipsoid\n");
        printf("8. Polyhedron\n");
        printf("0. Exit Program\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &figureChoice);
    } while (figureChoice < 0 || figureChoice > 8);

    return figureChoice;
}

int PyramidMenu()
{
    int pyramidChoice;

    do
    {
        note();
        printf("Choose a pyramid \n");
        printf("1. Triangular Pyramid\n");
        printf("2. Rectangular Pyramid\n");
        printf("3. Pentagonal Pyramid\n");
        printf("4. Hexagonal Pyramid\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &pyramidChoice);
    } while (pyramidChoice < 1 || pyramidChoice > 4);
    printf("\n");

    return pyramidChoice;
}

int PolyhedronMenu()
{
    int polyhedronChoice;

    do
    {
        note();
        printf("Choose a polyhedron \n");
        printf("1. Tetrahedron\n");
        printf("2. Octahedron\n");
        printf("3. Dodecahedron\n");
        printf("4. Icosahedron\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &polyhedronChoice);
    } while (polyhedronChoice < 1 || polyhedronChoice > 4);
    printf("\n");

    return polyhedronChoice;
}

int AreaMenu()
{
    int figureChoice;

    do
    {
        note();
        printf("Area Of Regular 2D Polygons:\n");
        printf("\n");
        printf("1. Triangle\n");
        printf("2. Square\n");
        printf("3. Pentagon\n");
        printf("4. Hexagon\n");
        printf("5. Heptagon\n");
        printf("6. Octagon\n");
        printf("7. Nonagon\n");
        printf("8. Decagon\n");
        printf("\n");
        printf("Select a 2D shape to be computed: ");
        scanf("%d", &figureChoice);
    } while (figureChoice < 1 || figureChoice > 8);
    printf("\n");

    return figureChoice;
}

// Perimeter Computation Functions
double SquarePerimeter()
{
    double input;

    printf("Enter length of side: ");
    scanf("%lf", &input);

    return input * 4;
}

double CirclePerimeter()
{
    double input;

    printf("Enter radius: ");
    scanf("%lf", &input);

    return input * 2 * M_PI;
}

double RectanglePerimeter()
{
    double length, width;

    printf("Enter length and width: \n");
    printf("Use commas to separate each number \n");
    scanf("%lf , %lf", &length, &width);

    return (length * 2) + (width * 2);
}

double TrianglePerimeter()
{
    double base, height;

    printf("Enter base and height: \n");
    printf("Use commas to separate each number \n");
    scanf("%lf , %lf", &base, &height);

    return (base * 2) + height;
}

double PolygonPerimeter()
{
    double side, length;

    printf("Enter the number of sides: ");
    scanf("%lf", &side);
    printf("Enter the length of each side: ");
    scanf("%lf", &length);

    return side * length;
}

// Volume Computation Functions
double CubeVolume()
{
    double length;
    char conversionChoice[100];

    do
    {
        printf("Please use only yes or no\n");
        printf("Is there a need for conversion? yes or no \n");
        scanf("%s", &conversionChoice);
        if (strstr(tolower(conversionChoice), "y"))
        // strstr() are used to check from first parameter if the second parameter exist. n here is if y exist in conversionChoice
        {
            length = Converter();
            break;
            // break is used to end the infinite loop
        }
        else if (strstr(tolower(conversionChoice), "n"))
        {
            printf("Enter length of edge: \n");
            scanf("%lf", &length);
            break;
        }
    } while (1);

    return length * length * length;
}

double CylinderVolume()
{
    double radius, height;

    printf("Enter radius and height: \n");
    printf("Use commas to separate each number\n");
    scanf("%lf, %lf", &radius, &height);

    return M_PI * radius * radius * height;
}

double PrismVolume()
{
    double length, width, height;

    printf("Enter length, width and height: \n");
    printf("Use commas to separate each number\n");
    scanf("%lf, %lf, %lf", &length, &width, &height);

    return length * width * height;
}

double ConeVolume()
{
    double radius, height;

    printf("Enter radius and height in: \n");
    printf("Use commas to separate each number\n");
    scanf("%lf, %lf", &radius, &height);

    return (M_PI * radius * radius * height) / 3;
}

double SphereVolume()
{
    double radius, height;

    printf("Enter radius: \n");
    scanf("%lf, %lf", &radius, &height);

    return (4 * M_PI * radius * radius * radius) / 3;
}

// const char * is used to return a string. the double* volume uses a pass by ref parameter.
// explaining pass by reference
// pass by reference is used to pass a variable to a function and the function will change the value of the variable
// example: void change(int *x) { *x = 10; }
// int main() { int x = 5; change(&x); printf("%d", x); }
// the output will be 10 because the function change() changed the value of x to 10
// reason of using it here is because we want to return a string and a double value
// by using this we can return both
// also instead of making multiple function with almost similar formula we use here 1 with multiple variations
// in comparison
const char *PyramidVolume(double *volume)
{
    double base, height;

    printf("Enter base length: ");
    scanf("%lf", &base);
    printf("Enter height: ");
    scanf("%lf", &height);

    switch (PyramidMenu())
    {
    case 1: // Triangular Pyramid
        *volume = (1.0 / 3.0) * 0.5 * base * height;
        return "Triangular Pyramid";

    case 2: // Rectangular Pyramid
        *volume = (1.0 / 3.0) * base * height;
        return "Rectangular Pyramid";

    case 3: // Pentagonal Pyramid
        *volume = (1.0 / 3.0) * 0.5 * 5 * base * height;
        return "Pentagonal Pyramid";

    case 4: // Hexagonal Pyramid
        *volume = (1.0 / 3.0) * 0.5 * 6 * base * height;
        return "Hexagonal Pyramid";
    }
}

double EllipsoidVolume()
{
    double smja, smna, asmna;

    printf("Enter semi-major axis: ");
    scanf("%lf", &smja);
    printf("Enter semi-minor axis: ");
    scanf("%lf", &smna);
    printf("Enter another semi-minor axis: ");
    scanf("%lf", &asmna);
    return (4.0 / 3.0) * M_PI * smja * smna * asmna;
}

double TetrahedronVolume()
{
    return (1.0 / 6.0) * sqrt(2.0) * pow(SideEntry(), 3);
}

double OctahedronVolume()
{
    return (1.0 / 3.0) * sqrt(2.0) * pow(SideEntry(), 3);
}

double IcosahedronVolume()
{
    return (5.0 / 12.0) * (3.0 + sqrt(5.0)) * pow(SideEntry(), 3);
}

double DodecahedronVolume()
{
    return (15.0 + 7.0 * sqrt(5.0)) / 4.0 * pow(SideEntry(), 3);
}

// Area of polygons
void TriangleArea()
{
    int x, y;

    printf("You Have Chosen Triangle!\n");
    printf("\n");
    printf("Enter base: ");
    scanf("%f", &x);
    printf("Enter height: ");
    scanf("%f", &y);
    printf("\n");

    if (x < 0 || x == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float tri = 0.5 * x * y;
    printf("Formula: 1/2 x Base x Height = Area\n");
    printf("Formula: 1/2 x %.2f x %.2f = %.2f\n", x, y, tri);
    printf("Area: %.2f\n", tri);
}

void RectangleArea()
{
    int x, y;

    printf("You Have Chosen Square!\n");
    printf("\n");
    printf("Enter length: ");
    scanf("%f", &x);
    printf("Enter width: ");
    scanf("%f", &y);
    printf("\n");

    if (x < 0 || x == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float square = x * y;
    printf("Formula: Length x Width = Area\n");
    printf("Formula: %.2f x %.2f = %.2f\n", x, y, square);
    printf("Area: %.2f\n", square);
}

void PentagonArea()
{
    int x, y;

    printf("You Have Chosen Pentagon!\n");
    printf("\n");
    printf("Enter side length: ");
    scanf("%f", &x);
    printf("\n");

    if (x < 0 || x == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float squared = pow(x, 2);
    float pentagon = 0.25 * squared * 6.881909602;
    printf("Formula: 1/4 x √5(5+2√5) x a^2 = Area\n");
    printf("Formula: 1/4 x 6.6881909602 x %.2f = %.2f\n", squared, pentagon);
    printf("Area: %.2f\n", pentagon);
}

void HexagonArea()
{
    int x, y;

    printf("You Have Chosen Hexagon!\n");
    printf("\n");
    printf("Enter side length: ");
    scanf("%f", &x);
    printf("\n");

    if (x < 0 || x == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float squared = pow(x, 2);
    float root = sqrt(3);
    float hexagon = 1.5 * root * squared;
    printf("Formula: 3/2 x √3 x a^2 = Area\n");
    printf("Formula: 3/2 x √3 x %.2f = %.2f\n", squared, hexagon);
    printf("Area: %.2f\n", hexagon);
}

void HeptagonArea()
{
    int x, y;

    printf("You Have Chosen Heptagon!\n");
    printf("\n");
    printf("Enter side length: ");
    scanf("%f", &x);

    if (x < 0 || x == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float squared = pow(x, 2);
    float angle = 1 / tan(M_PI / 7);
    float heptagon = (7 * squared * angle) / 4;
    printf("Formula: 7/4 x cot(π/7) x a^2 = Area\n");
    printf("Formula: 7/4 x cot(π/7) x %.2f = %.2f\n", squared, heptagon);
    printf("Area: %.2f\n", heptagon);
}

void OctagonArea()
{
    int x, y;

    printf("You Have Chosen Octagon!\n");
    printf("\n");
    printf("Enter side length: ");
    scanf("%f", &x);

    if (x < 0 || x == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float root = sqrt(2);
    float squared = pow(x, 2);
    float sum = 1 + root;
    float octagon = sum * 2 * squared;
    printf("Formula: 2 x (1+√2) x a^2 = Area\n");
    printf("Formula: 2 x (1+√2) x %.2f = %.2f\n", squared, octagon);
    printf("Area: %.2f\n", octagon);
}

void NonagonArea()
{
    int x, y;

    printf("You Have Chosen Nonagon!\n");
    printf("\n");
    printf("Enter side length: ");
    scanf("%f", &x);

    if (x < 0 || x == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float angle = 1 / tan(M_PI / 9);
    float squared = pow(x, 2);
    float nonagon = (angle * 9 * squared) / 4;
    printf("Formula: 9/4 x cot(π/9) x a^2 = Area\n");
    printf("Formula: 9/4 x cot(π/9) x %.2f = %.2f\n", squared, nonagon);
    printf("Area: %.2f\n", nonagon);
}

void DecagonArea()
{
    int x, y;

    printf("You Have Chosen Decagon!\n");
    printf("\n");
    printf("Enter side length: ");
    scanf("%f", &x);

    if (x < 0 || x == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float squared = pow(x, 2);
    float decagon = (3.077683537 * 5 * squared) / 2;
    printf("Formula: 5/2 x (√5+2√5)  x a^2 = Area\n");
    printf("Formula: 5/2 x (√5+2√5) x %.2f = %.2f\n", squared, decagon);
    printf("Area: %.2f\n", decagon);
}

// Utility Function
int Converter()
{
    double number, result;
    int choice;
    char *from;

    printf("Choose the conversion:\n");
    printf("1. Kilometers to Meters\n");
    printf("2. Centimeters to Meters\n");
    printf("3. Millimeters to Meters\n");
    printf("4. Inches to Meters\n");
    printf("5. Feet to Meters\n");
    printf("6. Yards to Meters\n");
    printf("7. Miles to Meters\n");
    printf("8. Nautical Miles to Meters\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the length to convert: ");
    scanf("%lf", &number);

    switch (choice)
    {
    case 1: // Kilometers to Meters
        result = number * 1000.0;
        from = "Kilometers";
        break;
    case 2: // Centimeters to Meters
        result = number * 0.01;
        from = "Centimeters";
        break;
    case 3: // Millimeters to Meters
        result = number * 0.001;
        from = "Millimeters";
        break;
    case 4: // Inches to Meters
        result = number * 0.0254;
        from = "Inches";
        break;
    case 5: // Feet to Meters
        result = number * 0.3048;
        from = "Feet";
        break;
    case 6: // Yards to Meters
        result = number * 0.9144;
        from = "Yards";
        break;
    case 7: // Miles to Meters
        result = number * 1609.34;
        from = "Miles";
        break;
    case 8: // Nautical Miles to Meters
        result = number * 1852.0;
        from = "Nautical Miles";
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    printf("%.2lf %s converted to meters is: %.2lf meters\n", from, number, result);
    return result;
}

double SideEntry()
{
    double side;

    printf("Enter side length: ");
    scanf("%lf", &side);

    return side;
}