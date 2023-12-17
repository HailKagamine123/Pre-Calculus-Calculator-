#include <stdio.h>

// Menu Functions
int MainMenu();
int AreaMenu();

// Area Functions
float AreaOfRectangle(float, float);
float AreaOfTriangle(float, float);
float AreaOfSquare(float);

// Perimeter Functions
float PerimeterOfRectangle(float, float);
float PerimeterOfTriangle(float, float, float);
float PerimeterOfSquare(float);


int main()
{
    int choice, area_choice;
    float length, width, side,base, height;
	float area_rec, area_squa, area_tria;

    choice = MainMenu();

	if (choice == 1)
	{
        area_choice = AreaMenu();

		if (area_choice == 1)
		{
			printf("Please enter the values of: \n");
			printf("Length: ");
			scanf("%f", &length);
			printf("Width: ");
			scanf("%f", &width);

			area_rec = AreaOfRectangle(length, width);
			printf("The area of the rectangle whose length is %.2f and whose width is %.2f is %.2f", length, width, area_rec);
		}
		else if(area_choice == 2)
		{
			printf("Please enter the value of side: ");
			scanf("%f", &side);

			area_squa = AreaOfSquare(side);
			printf("The area of the square who has the size of %.2f on every side is %.2f", side, area_squa);
		}
		else if (area_choice == 3)
		{
			printf("Enter the measurement of the base: ");
			scanf("%f", &base);
			printf("Enter the measurement of the height: ");
			scanf("%f",&height);

			area_tria= AreaOfTriangle(base,height);
			printf("The area of a triangle whose base is %.2f and has the height of %.2f is %.2f");
		}
	}
}

int MainMenu()
{
    int choice;

	printf(" Choose an operation\n");
	printf("1. Calculate the area\n");
	printf("2. Calculate the perimeter\n");
	printf("3. Calculate the volume\n"); //later kana
	printf("4. All about Circle\n");
	printf("5. Browse History\n");
	printf("5. Exit Program\n");
	printf("Enter choice: ");
	scanf("%d", &choice);

	return choice;


}

int AreaMenu()
{
    int area_choice;

    printf("What kind of area are you trying to find?\n");
    printf("1. Area of a rectangle\n");
    printf("2. Area of a square\n");
    printf("3. Area of a Triangle\n");
    printf("Enter choice: ");
    scanf("%d", &area_choice);

    return area_choice;
}

//Area of rectangle
float AreaOfRectangle(float length, float width)
{
	return length * width;
}

//Area of Triangle
float AreaOfTriangle(float base, float height)
{
	return 0.5 * base * height;
}

// Area of Square
float AreaOfSquare(float side)
{
	return side * side;
}

// Perimeter of rectangle
float PerimeterOfRectangle(float width, float lenght)
{
	return 2 * (lenght + width);
}

// Perimeter of a Triangle(naming it by the name of the 3 sides of the triangle para aesthetic)
float PerimeterOfTriangle(float hypotenuse, float adjacent, float opposite)
{
	return hypotenuse + adjacent + opposite;
}

// Perimeter of square
float PerimeterOfSquare(float side)
{
	return 4 * side;
}

