using System;
using System.Numerics;
using System.Runtime.InteropServices;
using System.Threading;

namespace MultiRoblox
{
    internal class Program
    {
        static void Main()
        {
            Console.CursorVisible = false;
            new Mutex(true, "ROBLOX_singletonMutex");
            Console.ForegroundColor = ConsoleColor.DarkBlue;
            string title = @"
  _____       _     _             __  __       _ _   _       _        _____           _                            
 |  __ \     | |   | |           |  \/  |     | | | (_)     | |      |_   _|         | |                           
 | |__) |___ | |__ | | _____  __ | \  / |_   _| | |_ _ _ __ | | ___    | |  _ __  ___| |_ __ _ _ __   ___ ___  ___ 
 |  _  // _ \| '_ \| |/ _ \ \/ / | |\/| | | | | | __| | '_ \| |/ _ \   | | | '_ \/ __| __/ _` | '_ \ / __/ _ \/ __|
 | | \ \ (_) | |_) | | (_) >  <  | |  | | |_| | | |_| | |_) | |  __/  _| |_| | | \__ \ || (_| | | | | (_|  __/\__ \
 |_|  \_\___/|_.__/|_|\___/_/\_\ |_|  |_|\__,_|_|\__|_| .__/|_|\___| |_____|_| |_|___/\__\__,_|_| |_|\___\___||___/
                                                      | |                                                          
                                                      |_|                                                          
";
            Console.WriteLine(title);
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("Made by Ausommet\n\n");
            Console.ForegroundColor = ConsoleColor.White;
            Console.Write("INSTRUCTIONS\n");
            Console.Write("Close all Roblox instances before running this");
            Console.ForegroundColor = ConsoleColor.White;
            Console.Write("\n\nNOTES\nYou can now open as many Roblox instances as you like using, ");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Write("seperate accounts");
            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine(". If you close this window, all Roblox instances except for one will close. Close all Roblox instances before activating this.\n");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Roblox Multi-Instance is now activated\n");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Write("Do not close this window.");
            Console.ForegroundColor = ConsoleColor.White;
            Thread.Sleep(-1);
        }
    }
}
