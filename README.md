Simple Math Game (C++)

A robust, console-based math quiz application built with C++. This game generates dynamic arithmetic problems based on user-defined difficulty levels and operation types, providing real-time feedback and a detailed performance summary.
🚀 Features

    Customizable Sessions: Users can choose to answer between 1 and 10 questions per round.

    Dynamic Difficulty: Supports four distinct levels:

        Easy: Numbers ranging from 1 to 10.

        Medium: Numbers ranging from 10 to 50.

        Hard: Numbers ranging from 50 to 100.

        Mix: A random rotation of all levels.

    Operation Variety: Choose between Addition, Subtraction, Multiplication, Division, or a "Mix" mode that alternates between them.

    Interactive UI:

        Visual Cues: The console background changes to Green for correct answers and Red for incorrect ones.

        Audio Alerts: An alert sound triggers upon a wrong answer.

    Performance Analytics: Provides a final result screen showing total questions, difficulty level, operation type, and a Pass/Fail status based on the score.

🛠️ Technical Details

The project demonstrates several fundamental C++ programming concepts:

    Structs & Enums: Used for organized data management of question states and quiz configurations.

    Randomization: Utilizes srand and time to ensure unique mathematical problems in every session.

    Flow Control: Implements do-while loops for game continuity and input validation.

    System Integration: Uses Windows system() commands for screen clearing and UI color manipulation.

🎮 How to Run

    Prerequisites: A C++ compiler (like GCC or MSVC) and a Windows environment (for full color/sound support).

    Compile:
    Bash

g++ Simple_Math_Game.cpp -o MathGame

Execute:
Bash

    ./MathGame

📖 How to Play

    Input Configuration: Enter the number of questions you wish to answer.

    Select Level: Choose your difficulty (1-4).

    Select Operation: Choose the math operator you want to practice (1-5).

    Solve: Input your answer for each question displayed.

    Review: Check your final stats at the end and choose 'Y' to play again or 'N' to exit.

📝 License

Distributed under the MIT License. See LICENSE for more information.
