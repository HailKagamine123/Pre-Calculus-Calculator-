#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Menu Prototypes
int MainMenu();
int AreaMenu();
int CircleMenu();
int VolumeMenu();
int PyramidMenu();
int PerimeterMenu();
int PolyhedronMenu();
void TransactionEnder();

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
const char *PyramidVolume(double *);
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

// Circle
float DiameterOfCircle(float);
float RadiusOfCircle(float, char);
float CircumferenceOfCircle(float);

// Utility Prototype
double DataInput(char *);
double ToMeterConverter();

/* Macro
    macro is used to define a constant value
    example: #define pi 3.14159
        pi is now a constant value of 3.14159, and you want to use it every time and don't need to change
    example: #define note() printf("\nPlease Select only from choices\n");
        note() is now a function that prints the string "Please Select only from choices" and you can use it every time
        note() is used in the main function
*/
#define PartSplitter() printf("\n----------------------------------------\n\n");
/* Macro Extended
    you can also do extended version of macro, here i'm using it to print the string "Please Select only from choices" with the recent macro from top PartSplitter().
    you just need \ at the end of the line to continue the macro
*/
#define Note()      \
    PartSplitter(); \
    ("Please Select only from choices\n\n");

int main()
{
    char type;
    double perimeter, volume;
    int menuChoice, circleChoice;
    float value, circumference, diameter, radius;
    char *perimeterSelectedName, *volumeSelectedName; // string holder

    float x, y, squared, angle;
    int shape;
    const double pi = 3.14159;
    char continue_choice;

    do
    {
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

            printf("The total perimeter of the %s is : %.2lf\n", perimeterSelectedName, perimeter);
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
                DecagonArea();
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
                    break;
                }
            default:
                printf("Invalid choice\n");
                break;
            }

            printf("The total volume of the %s is: %.2lf\n", volumeSelectedName, volume);
        }
        else if (menuChoice == 4)
        {
            circleChoice = CircleMenu();

            if (circleChoice == 1)
            {
                PartSplitter();
                value = DataInput("radius");

                circumference = CircumferenceOfCircle(value);
                printf("The circumference of the circle who has the radius of %.2f is %.2f.\n", value, circumference);
            }
            else if (circleChoice == 2)
            {
                PartSplitter();
                value = DataInput("radius");

                diameter = DiameterOfCircle(value);
                printf("The diameter of the circle who has the radius of %.2f is %.2f.\n", value, diameter);
            }
            else if (circleChoice == 3)
            {
                PartSplitter();
                value = DataInput("radius");

                printf("Enter 'd' if the value is a diameter of a circle and 'c' if it's a circumference of a circle.");
                scanf(" %c", &type);

                switch (type)
                {
                case 'd':
                    radius = RadiusOfCircle(value, type);
                    printf("The radius of the circle who has the diameter of %.2f is %.2f.\n", value, radius);
                    break;
                case 'c':
                    radius = RadiusOfCircle(value, type);
                    printf("The radius of the circle who has the circumference of %.2f is %.2f.\n", value, radius);
                    break;
                default:
                    break;
                }
            }
        }
        else if (menuChoice == 5)
        {
            // in process
        }
        else if (menuChoice == 0)
            return 0;

        TransactionEnder();
    } while (1);

    return 0;
}

// Menu Functions
int MainMenu()
{
    int required;

    do
    {
        Note();
        printf("Choose what you want to get:\n\n");
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
        Note();
        printf("What figure is it ?\n\n");
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
        Note();
        printf("What figure is it?\n\n");
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
        Note();
        printf("Choose a pyramid \n\n");
        printf("1. Triangular Pyramid\n");
        printf("2. Rectangular Pyramid\n");
        printf("3. Pentagonal Pyramid\n");
        printf("4. Hexagonal Pyramid\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &pyramidChoice);
    } while (pyramidChoice < 1 || pyramidChoice > 4);

    return pyramidChoice;
}

int PolyhedronMenu()
{
    int polyhedronChoice;

    PartSplitter();
    printf("Choose a polyhedron \n\n");
    printf("1. Tetrahedron\n");
    printf("2. Octahedron\n");
    printf("3. Dodecahedron\n");
    printf("4. Icosahedron\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d", &polyhedronChoice);

    return polyhedronChoice;
}

int AreaMenu()
{
    int figureChoice;

    do
    {
        Note();
        printf("Area Of Regular 2D Polygons:\n\n");
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

void TransactionEnder()
{
    // make a do while that check if user input is yes or no
    char choice[100];

    do
    {
        PartSplitter();
        printf("Do you want to continue? (y/n): ");
        scanf(" %s", &choice);
        printf("\n");

        /* what is strcspn?
            strcspn is a function that returns the length of the initial segment of the string str1 which consists entirely of characters not in the string str2.
        example:
            str1 = "Hello World"
            str2 = "abc"
            strcspn(str1, str2) = 10
            because the initial segment of str1 is "Hello Worl" and it consists entirely of characters not in str2
        */
    } while (!(strcspn(choice, "yn") <= 0));

    if (strcspn(choice, "n") <= 0)
    {
        printf("Thank you for using our program!\n");
        exit(0);
    }
}

int CircleMenu()
{
    int circleChoice;

    do
    {
        Note();
        printf("What do you want to get?\n\n");
        printf("1. Circumference\n");
        printf("2. Diameter\n");
        printf("3. Radius\n");
        printf("\n");
        printf("Select a Formula: ");
        scanf("%d", &circleChoice);
    } while (circleChoice < 1 || circleChoice > 3);

    return circleChoice;
}

// Perimeter Computation Functions
double SquarePerimeter()
{
    double input;

    PartSplitter();
    input = DataInput("side length");

    return input * 4;
}

double CirclePerimeter()
{
    double input;

    PartSplitter();
    input = DataInput("radius");

    return input * 2 * M_PI;
}

double RectanglePerimeter()
{
    double length, width;

    PartSplitter();
    printf("Enter length and width: \n");
    printf("Use commas to separate each number \n");
    scanf("%lf , %lf", &length, &width);

    return (length * 2) + (width * 2);
}

double TrianglePerimeter()
{
    double base, height;

    PartSplitter();
    printf("Enter base and height: \n");
    printf("Use commas to separate each number \n");
    scanf("%lf , %lf", &base, &height);

    return (base * 2) + height;
}

double PolygonPerimeter()
{
    double side, length;

    side = DataInput("number of sides");
    length = DataInput("length of each side");

    return side * length;
}

// Volume Computation Functions
double CubeVolume()
{
    double length;
    char conversionChoice[100];

    do
    {
        PartSplitter();
        printf("Please use only yes or no\n");
        printf("Is there a need for conversion? yes or no \n");
        scanf("%s", &conversionChoice);

        PartSplitter();
        if (strcspn(conversionChoice, "y") <= 0)
        {
            length = ToMeterConverter();
            PartSplitter();
            break;
            // break is used to end the infinite loop
        }
        else if (strcspn(conversionChoice, "n") <= 0)
        {
            length = DataInput("length");
            break;
        }
    } while (1);

    return length * length * length;
}

double CylinderVolume()
{
    double radius, height;

    PartSplitter();
    printf("Enter radius and height: \n");
    printf("Use commas to separate each number\n");
    scanf("%lf, %lf", &radius, &height);

    return M_PI * radius * radius * height;
}

double PrismVolume()
{
    double length, width, height;

    PartSplitter();
    printf("Enter length, width and height: \n");
    printf("Use commas to separate each number\n");
    scanf("%lf, %lf, %lf", &length, &width, &height);

    return length * width * height;
}

double ConeVolume()
{
    double radius, height;

    PartSplitter();
    printf("Enter radius and height in: \n");
    printf("Use commas to separate each number\n");
    scanf("%lf, %lf", &radius, &height);

    return (M_PI * radius * radius * height) / 3;
}

double SphereVolume()
{
    double radius, height;

    PartSplitter();
    printf("Enter radius: \n");
    scanf("%lf, %lf", &radius, &height);

    return (4 * M_PI * radius * radius * radius) / 3;
}

// const char * is used to return a string. the double* volume uses a pass by ref parameter.
const char *PyramidVolume(double *volume)
{
    double base, height;

    PartSplitter();
    base = DataInput("base");
    height = DataInput("height");

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

    PartSplitter();
    smja = DataInput("Semi-major axis");
    smna = DataInput("Semi-minor axis");
    asmna = DataInput("Asymptotic length of semi-minor axis");
    return (4.0 / 3.0) * M_PI * smja * smna * asmna;
}

double TetrahedronVolume()
{
    return (1.0 / 6.0) * sqrt(2.0) * pow(DataInput("Side Length"), 3);
}

double OctahedronVolume()
{
    return (1.0 / 3.0) * sqrt(2.0) * pow(DataInput("Side Length"), 3);
}

double DodecahedronVolume()
{
    return (15.0 + 7.0 * sqrt(5.0)) / 4.0 * pow(DataInput("Side Length"), 3);
}

double IcosahedronVolume()
{
    return (5.0 / 12.0) * (3.0 + sqrt(5.0)) * pow(DataInput("Side Length"), 3);
}

// Area of polygons
void TriangleArea()
{
    int base, height;

    PartSplitter();
    printf("You Have Chosen Triangle!\n\n");
    base = DataInput("Base");
    height = DataInput("Height");

    if (base < 0 || base == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float tri = 0.5 * base * height;
    printf("Formula: 1/2 x Base x Height = Area\n");
    printf("Formula: 1/2 x %.2f x %.2f = %.2f\n", base, height, tri);
    printf("Area: %.2f\n", tri);
}

void RectangleArea()
{
    int length, width;

    PartSplitter();
    printf("You Have Chosen Square!\n\n");
    length = DataInput("Length");
    width = DataInput("Width");

    if (length < 0 || length == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float square = length * width;
    printf("Formula: Length x Width = Area\n");
    printf("Formula: %.2f x %.2f = %.2f\n", length, width, square);
    printf("Area: %.2f\n", square);
}

void PentagonArea()
{
    int length;

    PartSplitter();
    printf("You Have Chosen Pentagon!\n\n");
    length = DataInput("Side Length");

    if (length < 0 || length == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float squared = pow(length, 2);
    float pentagon = 0.25 * squared * 6.881909602;
    printf("Formula: 1/4 x √5(5+2√5) x a^2 = Area\n");
    printf("Formula: 1/4 x 6.6881909602 x %.2f = %.2f\n", squared, pentagon);
    printf("Area: %.2f\n", pentagon);
}

void HexagonArea()
{
    int length;

    PartSplitter();
    printf("You Have Chosen Hexagon!\n\n");
    length = DataInput("Side Length");

    if (length < 0 || length == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float squared = pow(length, 2);
    float root = sqrt(3);
    float hexagon = 1.5 * root * squared;
    printf("Formula: 3/2 x √3 x a^2 = Area\n");
    printf("Formula: 3/2 x √3 x %.2f = %.2f\n", squared, hexagon);
    printf("Area: %.2f\n", hexagon);
}

void HeptagonArea()
{
    int length;

    PartSplitter();
    printf("You Have Chosen Heptagon!\n\n");
    length = DataInput("Side Length");

    if (length < 0 || length == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float squared = pow(length, 2);
    float angle = 1 / tan(M_PI / 7);
    float heptagon = (7 * squared * angle) / 4;
    printf("Formula: 7/4 x cot(π/7) x a^2 = Area\n");
    printf("Formula: 7/4 x cot(π/7) x %.2f = %.2f\n", squared, heptagon);
    printf("Area: %.2f\n", heptagon);
}

void OctagonArea()
{
    int length;

    PartSplitter();
    printf("You Have Chosen Octagon!\n");
    printf("\n");
    length = DataInput("Side Length");

    if (length < 0 || length == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float root = sqrt(2);
    float squared = pow(length, 2);
    float sum = 1 + root;
    float octagon = sum * 2 * squared;
    printf("Formula: 2 x (1+√2) x a^2 = Area\n");
    printf("Formula: 2 x (1+√2) x %.2f = %.2f\n", squared, octagon);
    printf("Area: %.2f\n", octagon);
}

void NonagonArea()
{
    int length;

    PartSplitter();
    printf("You Have Chosen Nonagon!\n");
    printf("\n");
    length = DataInput("Side Length");

    if (length < 0 || length == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float angle = 1 / tan(M_PI / 9);
    float squared = pow(length, 2);
    float nonagon = (angle * 9 * squared) / 4;
    printf("Formula: 9/4 x cot(π/9) x a^2 = Area\n");
    printf("Formula: 9/4 x cot(π/9) x %.2f = %.2f\n", squared, nonagon);
    printf("Area: %.2f\n", nonagon);
}

void DecagonArea()
{
    int length;

    PartSplitter();
    printf("You Have Chosen Decagon!\n");
    printf("\n");
    length = DataInput("Side Length");

    if (length < 0 || length == 'a')
    {
        printf("INVALID VALUE!");
        return;
    }
    float squared = pow(length, 2);
    float decagon = (3.077683537 * 5 * squared) / 2;
    printf("Formula: 5/2 x (√5+2√5)  x a^2 = Area\n");
    printf("Formula: 5/2 x (√5+2√5) x %.2f = %.2f\n", squared, decagon);
    printf("Area: %.2f\n", decagon);
}

// Circle
float DiameterOfCircle(float value)
{
    return 2 * value;
}

float RadiusOfCircle(float value, char type)
{
    if (type == 'd')
    {
        return value / 2;
    }
    else if (type == 'c')
    {
        return value / (2 * 3.14159);
    }
    else
    {
        return -1;
    }
}

float CircumferenceOfCircle(float value)
{
    return 2 * 3.14159 * value;
}

// Utility Function
double ToMeterConverter()
{
    double number, result;
    int choice;
    char *from;

    printf("Choose the conversion:\n\n");
    printf("1. Kilometers to Meters\n");
    printf("2. Centimeters to Meters\n");
    printf("3. Millimeters to Meters\n");
    printf("4. Inches to Meters\n");
    printf("5. Feet to Meters\n");
    printf("6. Yards to Meters\n");
    printf("7. Miles to Meters\n");
    printf("8. Nautical Miles to Meters\n\n");
    choice = DataInput("your choice");

    number = DataInput("the length to convert");

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
    printf("%.2lf %s converted to meters is: %.2lf meters\n", number, from, result);
    return result;
}

double DataInput(char *requirement)
{
    double side;

    printf("Enter %s: ", requirement);
    scanf("%lf", &side);

    return side;
}