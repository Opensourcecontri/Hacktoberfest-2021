using System;
using System.Collections.Generic;
using System.Linq;

namespace HW1
{
    class Program
    {
        static void Main(string[] args)
        {
            //Select your exercise as method
        }

        private static void Ex1()
        {
            Console.WriteLine("Enter 2 numbers");
            Console.WriteLine("Enter first number");
            double a = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Enter second number");
            double b = Convert.ToDouble(Console.ReadLine());
            Console.Write("Choose your action: \n1.Add\n2.Substract\n3.Multiply\n4.Divide\n");
            UInt32 act = Convert.ToUInt32(Console.ReadLine());

            switch (act)
            {
                case 1:
                    Console.WriteLine($"Adding the result is: {a + b}");
                    break;

                case 2:
                    Console.WriteLine($"Substracting the result is: {a - b}");
                    break;

                case 3:
                    Console.WriteLine($"Multiplying the result is: {a * b}");
                    break;

                case 4:
                    Console.WriteLine($"Dividing the result is: {a / b}");
                    break;

                default:
                    Console.WriteLine("You have pressed wrong action");
                    break;
            }

        }

        private static void Ex2()
        {
            var list = new List<int>();

            Console.WriteLine("Enter 4 number and get a average");
            for (var i = 0; i < 4; i++)
            {
                Console.WriteLine($"Enter the number no {i + 1}");
                list.Add(Convert.ToInt32(Console.ReadLine()));
            }

            Console.Write($"The average is {list.Average()}");
        }

        private static void Ex3()
        {
            Console.WriteLine("Enter three number X Y Z");
            Console.WriteLine("Enter X");
            double x = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Enter Y");
            double y = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Enter Z");
            double z = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine($"The result of (x + y) * z is {(x + y) * z}\nThe result of x * y is {x * y} ");


        }

        private static void Ex4()
        {
            Console.Write("Enter the temperature in celsius: ");

            var celsius = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("In Kelvins: {0}", celsius + 273.15);
            Console.WriteLine("In Fahrenheit: {0}", celsius * 18 / 10 + 32);
        }

        private static void Ex5()
        {
            Console.Write("Enter the number in HEX: ");

            var hex = Console.ReadLine(); //C1A
            double result = 0.0;


            var count = hex.Length - 1;
            for (int i = 0; i < hex.Length; i++)
            {

                switch (hex[i])
                {
                    case 'A':
                        result += 10 * Math.Pow(16, count);
                        break;

                    case 'B':
                        result += 11 * Math.Pow(16, count);
                        break;

                    case 'C':
                        result += 12 * Math.Pow(16, count);
                        break;

                    case 'D':
                        result += 13 * Math.Pow(16, count);
                        break;

                    case 'E':
                        result += 14 * Math.Pow(16, count);
                        break;

                    case 'F':
                        result += 15 * Math.Pow(16, count);
                        break;

                    default:
                        result += char.GetNumericValue(hex[i]) * Math.Pow(16, count);
                        break;
                }

                count--;

            }

            Console.WriteLine($"Number in decimal is: {result}");
        }
    }
}
