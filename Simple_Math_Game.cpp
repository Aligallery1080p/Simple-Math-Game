#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, MixLevel = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };

struct stQuestion
{
	short Number1;
	short Number2;
	enOperationType OpType;
	enQuestionLevel QuestionLevel;
	int PlayerAnswer;
	int CorrectAnswer;
	bool isAnswerCorrect;
};

struct stQuizz
{
	short NumberOfQuestions;
	enQuestionLevel QuestionsLevel;
	enOperationType OperationType;
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
};

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

int ReadHowManyQuestions()
{
	int NumberOfQuestions;

	do
	{
		cout << "How Many Questions do you want to answer ? ";
		cin >> NumberOfQuestions;

	} while (NumberOfQuestions < 1 || NumberOfQuestions > 10);

	return NumberOfQuestions;
}

enQuestionLevel ReadQuestionsLevel()
{
	short QuestionsLevel;

	do
	{
		cout << "Enter Questions Level [1]: Easy, [2]: Med, [3]: Hard, [4]: Mix ? ";
		cin >> QuestionsLevel;

	} while (QuestionsLevel < 1 || QuestionsLevel > 4);
	
	return enQuestionLevel(QuestionsLevel);
}

enOperationType ReadOpType()
{
	short OpType;

	do
	{
		cout << "Enter Operation Type [1]: Add, [2]: Sub, [3]: Mul, [4]: Div, [5]: Mix ? ";
		cin >> OpType;

	} while (OpType < 1 || OpType > 5);

	return enOperationType(OpType);
}

char GetOpTypeSymbol(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return '+';
		break;

	case enOperationType::Sub:
		return '-';
		break;

	case enOperationType::Mul:
		return '*';
		break;

	case enOperationType::Div:
		return '/';
		break;
	}
}

int ReadPlayerAnswer()
{
	int PlayerAnswer;
	cin >> PlayerAnswer;
	return PlayerAnswer;
}

int SimpleCalculator(stQuestion Question)
{
	switch (Question.OpType)
	{
	case enOperationType::Add:
		return Question.Number1 + Question.Number2;
		break;

	case enOperationType::Sub:
		return Question.Number1 - Question.Number2;
		break;

	case enOperationType::Mul:
		return Question.Number1 * Question.Number2;
		break;

	case enOperationType::Div:
		return Question.Number1 / Question.Number2;
	}
}

stQuestion GenerateQuestion(stQuizz Quizz)
{
	stQuestion Question;

	if (Quizz.OperationType == enOperationType::MixOp)
		Question.OpType = enOperationType(RandomNumber(1, 4));
	else
		Question.OpType = Quizz.OperationType;

	if (Quizz.QuestionsLevel == enQuestionLevel::MixLevel)
		Question.QuestionLevel = enQuestionLevel(RandomNumber(1, 3));
	else
		Question.QuestionLevel = Quizz.QuestionsLevel;

	switch (Question.QuestionLevel)
	{
	case enQuestionLevel::Easy:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		break;

	case enQuestionLevel::Med:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);
		break;

	case enQuestionLevel::Hard:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);
		break;
	}

	cout << Question.Number1 << endl;
	cout << Question.Number2 << " " << GetOpTypeSymbol(Question.OpType) << endl;
	cout << "_________\n";
	Question.PlayerAnswer = ReadPlayerAnswer();
	Question.CorrectAnswer = SimpleCalculator(Question);
	Question.isAnswerCorrect = (Question.PlayerAnswer == Question.CorrectAnswer);

	return Question;
}

string GetQuestionLevelName(enQuestionLevel QuestionLevel)
{
	string arrQuestionLevel[4] = { "Easy","Med","Hard","Mix" };
	return arrQuestionLevel[QuestionLevel - 1];
}

string GetOpTypeName(enOperationType OpType)
{
	string arrOpTypeName[5] = { "Add","Sub","Mul","Div","Mix" };
	return arrOpTypeName[OpType - 1];
}

stQuizz PlayMathGame(short HowManyQuestions)
{	
	stQuizz Quizz;

	Quizz.NumberOfQuestions = HowManyQuestions;
	Quizz.QuestionsLevel = ReadQuestionsLevel();
	Quizz.OperationType = ReadOpType();

	for (short QuestionNumber = 1;QuestionNumber <= Quizz.NumberOfQuestions;QuestionNumber++)
	{
		cout << "\nQuestion [" << QuestionNumber << "/" << Quizz.NumberOfQuestions << "]\n\n";
		stQuestion Question = GenerateQuestion(Quizz);
		
		if (Question.isAnswerCorrect == false)
		{
			cout << "Wrong Answer :-(\n";
			cout << "The right answer is: " << Question.CorrectAnswer << endl << endl;
			cout << "\a";
			system("color 4F");
			Quizz.NumberOfWrongAnswers++;
			
		}
		else
		{
			cout << "Right Answer :-)\n\n";
			Quizz.NumberOfRightAnswers++;
			system("color 2F");
		}
	}

	return Quizz;
}

void ShowFinalResultScreen(short NumberOfRightAnswers, short NumberOfWrongAnswers)
{
	cout << "\n______________________________\n\n";
	cout << " Final Results is ";

	if (NumberOfRightAnswers >= NumberOfWrongAnswers)
		cout << "PASS :-)\n";
	else
		cout << "Fail :-)\n";

	cout << "______________________________\n\n";
}

void ShowQuizzResults(stQuizz Quizz)
{
	cout << "Number of Questions: " << Quizz.NumberOfQuestions << endl;
	cout << "Questions Level    : " << GetQuestionLevelName(Quizz.QuestionsLevel) << endl;
	cout << "OpType             : " << GetOpTypeName(Quizz.OperationType) << endl;
	cout << "Number of Right Answers: " << Quizz.NumberOfRightAnswers << endl;
	cout << "Number of Wrong Answers: " << Quizz.NumberOfWrongAnswers << endl;
	cout << "______________________________\n\n";
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain;

	do
	{
		ResetScreen();
		stQuizz Quizz = PlayMathGame(ReadHowManyQuestions());
		ShowFinalResultScreen(Quizz.NumberOfRightAnswers, Quizz.NumberOfWrongAnswers);
		ShowQuizzResults(Quizz);

		cout << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}