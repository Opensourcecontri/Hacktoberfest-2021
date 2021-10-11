using System;
using System.Collections.Generic;
using System.Linq;

namespace Lab3_02_11_2020
{
    class Program
    {
        static void Main(string[] args)
        {
            Ex5a();
        }

        public static void Ex1()
        {
            Console.WriteLine("Enter 3 values");
            var arr = new List<int>();
            for (int i = 0; i < 3; i++)
            {

                arr.Add(Convert.ToInt32(Console.ReadLine()));
            }

            Console.WriteLine($"The greatest is {arr.Max()}");
            Console.WriteLine($"The lowest is {arr.Min()}");

        }

        public static void Ex2()
        {
            Console.WriteLine("Enter 3 grades");
            var arr = new List<int>();
            for (int i = 0; i < 3; i++)
            {

                arr.Add(Convert.ToInt32(Console.ReadLine()));
            }

            Console.WriteLine($"The grade of student is {arr.Average()}");

        }

        public static void Ex3()
        {
            Console.WriteLine("Enter number");
            var a = Convert.ToInt32(Console.ReadLine());

            if (a > 0)
            {
                Console.WriteLine("num is pos");
            }
            else if (a < 0)
            {
                Console.WriteLine("num is neg");
            }
            else
            {
                Console.WriteLine("num is 0");
            }
        }

        public static void Ex4()
        {
            Console.WriteLine("Enter number");
            var a = Convert.ToInt32(Console.ReadLine());

            if (a % 2 == 0)
            {
                Console.WriteLine("num is even");
            }
            else
            {
                Console.WriteLine("num is odd");
            }
        }

        public static void Ex5()
        {
            Console.WriteLine("Enter char");
            var ch = Console.ReadLine();

            if (ch.Length > 1)
            {
                Console.WriteLine("It's a sentence");
            }
            else
            {
                Console.WriteLine("It's a char");
            }

        }

        public static void Ex6()
        {
            Console.WriteLine("enter the month num");
            var a = Convert.ToInt32(Console.ReadLine());
            if (a > 0 && a <= 12)
            {
                Console.WriteLine(DateTime.DaysInMonth(DateTime.Now.Year, a));

            }


        }

        public static void Ex1a()
        {
            while (true)
            {
                var a = Console.ReadLine();
                string num = "0123456789";
                //Console.WriteLine(a);

                if (num.Contains(a))
                {
                    Console.WriteLine(a);
                }
                else
                {
                    Console.WriteLine("not allowed");
                }
            }


        }

        public static void Ex2a()
        {
            Console.WriteLine("Choose your action");
            var act = Console.ReadLine();
            Console.WriteLine("Enter num 1");
            var a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter num 2");
            var b = Convert.ToInt32(Console.ReadLine());

            switch (act)
            {
                case "+":
                    Console.WriteLine(a + b);
                    return;

                case "-":
                    Console.WriteLine(a - b);
                    return;

                case "*":
                    Console.WriteLine(a * b);
                    return;

                case "/":
                    Console.WriteLine(a / b);
                    return;

                default:
                    Console.WriteLine("Wrong input");
                    return;
            }

        }

        public static void Ex3a()
        {
            Console.WriteLine("Enter num in bin");
            var a = Console.ReadLine();

            var hex = Convert.ToInt32(a, 2).ToString("X");

            Console.WriteLine($"Hex is {hex}");
        }

        public static void Ex4a()
        {
            Console.WriteLine("enter the num");
            var n = Convert.ToInt32(Console.ReadLine());
            var sum = 0;
            for (int i = 1; i < n; i++)
            {
                if (n % i == 0)
                {
                    sum = sum + i;
                }
            }
            if (sum == n)
                Console.WriteLine("num is perf");
            else
                Console.WriteLine("num is not perf");

        }

        public static void Ex5a()
        {
            Console.WriteLine("Enter the num");
            var n = Convert.ToInt32(Console.ReadLine());
            Console.Write($"{n} = 1");
            for (var i = 0; n % 2 == 0; n /= 2)
            {
                Console.Write($" * {2}");
            }
            for (var i = 3; i <= n;)
            {
                if (n % i == 0)
                {
                    Console.Write($" * {i}");
                    n /= i;
                }
                else
                {
                    i += 2;
                }
            }

        }


    }
}
