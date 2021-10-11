using System;

namespace Lab2_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //Ex7();
        }

        public static void Ex1()
        {
            Console.WriteLine("Enter number and check if a given positive number is a multiple of 3 or a multiple of 7");

            var a = Convert.ToInt32(Console.ReadLine());

            if (a % 7 == 0 && a % 3 == 0)
            {
                Console.WriteLine("This number can multiple of 7 and 3");
            }
            else if (a % 7 == 0)
            {
                Console.WriteLine("This number can multiple of 7");
            }
            else if (a % 3 == 0)
            {
                Console.WriteLine("This number can multiple of 3");
            }
            else
            {
                Console.WriteLine("This number cant multiple of 7 or 3");
            }

        }

        public static void Ex2()
        {
            Console.WriteLine("Enter two numbers and check if an integer (from the two given integers) is in the range -10 to 10");
            Console.WriteLine("Enter number 1: ");
            var a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter number 2: ");
            var b = Convert.ToInt32(Console.ReadLine());

            if (a > -10 && a < 10 && b > -10 && b < 10)
            {
                Console.WriteLine("Both number are between 10 and -10");
            }
            else if (a > -10 && a < 10)
            {
                Console.WriteLine("First number is between 10 and -10");
            }
            else if (b > -10 && b < 10)
            {
                Console.WriteLine("Second number is between 10 and -10");
            }
            else
            {
                Console.WriteLine("No number between 10 and -10");
            }
        }

        public static void Ex3()
        {
            Console.WriteLine("Enter two numbers and check two given numbers where one is less than 100 and other is greater than 200");
            Console.WriteLine("Enter number 1: ");
            var a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter number 2: ");
            var b = Convert.ToInt32(Console.ReadLine());

            if (a < 100 && b > 200)
            {
                Console.WriteLine("One is less than 100 and other is greater than 200");
            }
            else
            {
                Console.WriteLine("Not - one is less than 100 and other is greater than 200");
            }
        }

        public static void Ex4()
        {
            Console.WriteLine("Enter  the radius of a circle as input and calculate the perimeter and area of the circle");
            Console.WriteLine("Enter radius: ");
            var a = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine($"Area is {Math.PI * a * a}, Perimeter is {2 * Math.PI * a}" );

        }

        public static void Ex5()
        {
            Console.WriteLine("Enter  the takes distance and time (distance in meters, time in hours) as input and displays the speed in kilometers per hour and miles per hour");
            Console.WriteLine("Enter distance: ");
            var a = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Enter time: ");
            var b = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine($"Speed is {a / b} (km/h), Speed is { (a / b ) / 1.609} (mph)");

        }

        public static void Ex6()
        {
            Console.WriteLine("Enter the radius and calculate surface and volume");
            Console.WriteLine("Enter radius: ");
            var a = Convert.ToDouble(Console.ReadLine());


            Console.WriteLine($"Surface is {4 * Math.PI * a * a} , Volume is { (4 / 3) * Math.PI * (a * a * a)}");

        }

        public static void Ex7()
        {
            Console.WriteLine("Enter two numbers as input and returns true or false when both numbers are even or odd");
            Console.WriteLine("Enter first number: ");
            var a = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Enter second number: ");
            var b = Convert.ToDouble(Console.ReadLine());

            if (a % 2 == 0 && b % 2 == 0)
            {
                Console.WriteLine("True");
            }
            else
            {
                Console.WriteLine("False");
            }


        }
    }
}
