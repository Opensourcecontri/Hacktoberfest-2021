using System;

namespace Lab2
{
    class Program
    {
        static void Main(string[] args)
        {
            // Choose method
            // Ex5();
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
            Console.WriteLine("Enter the number of multiplication u want");
            var a = Convert.ToInt32(Console.ReadLine());

            for (int i = 1; i < 11; i++)
            {
                Console.WriteLine($"{a} * {i} = {a * i}");
            }
        }

        private static void Ex3()
        {
            Console.WriteLine("Enter 2 numbers");
            Console.WriteLine("Enter first number");
            double a = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Enter second number");
            double b = Convert.ToDouble(Console.ReadLine());

            if (a < 0 && b > 0)
            {
                Console.WriteLine("True");
            }
            else if (b < 0 && a > 0)
            {
                Console.WriteLine("True");
            }
            else
            {
                Console.WriteLine("False");
            }
        }

        private static void Ex4()
        {
            Console.WriteLine("Enter a number");
            double a = Convert.ToDouble(Console.ReadLine());

            if (a > 20 && a < 100)
            {
                Console.WriteLine("Your num is between 20 and 100");
            }
            else
            {
                Console.WriteLine("Your num is not between 20 and 100");
            }

        }

        private static void Ex5()
        {
            Console.WriteLine("Printing odd numbers between 1 to 99");

            for (int i = 1; i <= 99; i+=2)
            {
                Console.WriteLine(i);
            }
        }


    }
}
