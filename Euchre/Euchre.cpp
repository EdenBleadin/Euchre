#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <string>

class Card {       
public:            
	int Value = 0;        
	int Suit = 0;
	std::string Name;
};
class Player {
public:
	int Team = 0;
	std::vector<Card> Hand;
	std::string Name;
};
std::vector<Player> Players;
std::vector<int> Cards = { 11,12,13,14,15,16,17,  21,22,23,24,25,26,27,  31,32,33,34,35,36,37,  41,42,43,44,45,46,47, };
//Use remaider fucntion %
//Hearts and diamonds are 1&2
//Clubs and Spades are 3&4
std::vector<Card> Player1;
std::vector<Card> Player2;
std::vector<Card> Player3;
std::vector<Card> Player4;
std::vector<int> DealerHand;
std::vector<Card> InPlay;
std::vector<int> CardRank;
int Trump;
bool DrawDone = false;

void rank() 
{
	switch (Trump) {
	case 1:
		//Hearts
		//14=19
		//24=18
		break;
	case 2:
		//Diamonds
		//24=29
		//14=28
		break;
	case 3:
		//Clubs
		//34=39
		//44=38
		break;
	case 4:
		//Spades
		//44=49
		//34=48
		break;
	default:
		printf("This shouldnt happen");
	}
}

void randomizer()
{
	std::random_shuffle(InPlay.begin(), InPlay.end());
}

void drawprint()
{
	Player1.emplace_back(InPlay.back());
	std::cout << "Player 1 drew " + InPlay.back().Name + "\n";
	InPlay.pop_back();
	Player2.emplace_back(InPlay.back());
	std::cout << "Player 2 drew " + InPlay.back().Name + "\n";
	InPlay.pop_back();
	Player3.emplace_back(InPlay.back());
	std::cout << "Player 3 drew " + InPlay.back().Name + "\n";
	InPlay.pop_back();
	Player4.emplace_back(InPlay.back());
	std::cout << "Player 4 drew " + InPlay.back().Name + "\n";
	InPlay.pop_back();
}
void draw()
{
	Player1.emplace_back(InPlay.back());
	InPlay.pop_back();
	Player2.emplace_back(InPlay.back());
	InPlay.pop_back();
	Player3.emplace_back(InPlay.back());
	InPlay.pop_back();
	Player4.emplace_back(InPlay.back());
	InPlay.pop_back();
}

std::string NameReturn(int Card)
{
	std::string Name1;
	std::string Name2;
	bool TrumpJacks = false;
	switch (Card % 10) {
	case 1:
		Name1 = "Eight of";
		break;
	case 2:
		Name1 = "Nine of";
		break;
	case 3:
		Name1 = "Ten of";
		break;
	case 4:
		Name1 = "Jack of";
		break;
	case 5:
		Name1 = "Queen of";
		break;
	case 6:
		Name1 = "King of";
		break;
	case 7:
		Name1 = "Ace of";
		break;
	case 8:
		Name1 = "Jack of";
		TrumpJacks = true;
		break;
	case 9:
		Name1 = "Jack of";
		break;
	default:
		printf("This shouldnt happen");
	}
	switch (Card/10) {
	case 1:
		Name2 = " Hearts";
		if (TrumpJacks == true)
		{
			Name2 = " Diamonds";
		}
		break;
	case 2:
		Name2 = " Diamonds";
		if (TrumpJacks == true)
		{
			Name2 = " Hearts";
		}
		break;
	case 3:
		Name2 = " Clubs";
		if (TrumpJacks == true)
		{
			Name2 = " Spades";
		}
		break;
	case 4:
		Name2 = " Spades";
		if (TrumpJacks == true)
		{
			Name2 = " Clubs";
		}
		break;
	default:
		printf("This shouldnt happen");
	}
	std::string Name = Name1 + Name2;
	return Name;
}

void PlayerTeams()
{
	int Ranking1 = 100;
	int Ranking2 = 200;
	int Ranking3 = 300;
	int Ranking4 = 400;
	for (int y = 0; y < size(Player1); y++)
	{
		
		Ranking1 += Player1[y].Value;
		
	}
	for (int y = 0; y < size(Player2); y++)
	{

		Ranking2 += Player2[y].Value;

	}
	for (int y = 0; y < size(Player3); y++)
	{

		Ranking3 += Player3[y].Value;

	}
	for (int y = 0; y < size(Player4); y++)
	{

		Ranking4 += Player4[y].Value;

	}
	Player1.clear();
	Player2.clear();
	Player3.clear();
	Player4.clear();
	int First;
	int First2;
	int Second;
	int Second2;
	int Third;
	int Third2;
	int Third3;
	int Third4;
	
	if (Ranking1%100 - Ranking2 % 100 > 0)
	{
		First = Ranking1;
		First2 = Ranking2;
	}
	else if (Ranking1 % 100 - Ranking2 % 100 < 0)
	{
		First = Ranking2;
		First2 = Ranking1;
	}
	else
	{
		printf("Player 1 and 2 tied, restarting team assignment\n");
		return;
	}

	if (Ranking3 % 100 - Ranking4 % 100 > 0)
	{
		Second = Ranking3;
		Second2 = Ranking4;
	}
	else if (Ranking3 % 100 - Ranking4 % 100 < 0)
	{
		Second = Ranking4;
		Second2 = Ranking3;
	}
	else
	{
		printf("Player 3 and 4 tied, restarting team assignment\n");
		return;
	}
	if (First % 100 - Second % 100 > 0)
	{
		Third = First;
		Third2 = Second;
		Third3 = First2;
		Third4 = Second2;
	}
	else if (First % 100 - Second % 100 < 0)
	{
		Third = Second;
		Third2 = First;
		Third3 = Second2;
		Third4 = First2;
	}
	else
	{
		std::cout << "Player "; 
		std::cout << First / 100; 
		std::cout << "and Player ";
		std::cout << Second / 100 + "tied, restarting team assignment\n";
		return;
	}
	if (Third2 % 100 - Third3 % 100 > 0)
	{
		if (Third3 % 100 - Third4 % 100 > 0)
		{

		}
		else if (Third3 % 100 - Third4 % 100 < 0)
		{
			int x = Third3;
			Third3 = Third4;
			Third4 = x;
		}
		else
		{
			std::cout << "Player ";
			std::cout << Third3 / 100;
			std::cout << "and Player ";
			std::cout << Third4 / 100 + "tied, restarting team assignment\n";
			return;
		}
	}
	else if (Third2 % 100 - Third3 % 100 < 0)
	{
		int x = Third2;
		Third2 = Third3;
		Third3 = x;
	}
	else
	{
		std::cout << "Player ";
		std::cout << Third2 / 100;
		std::cout << "and Player ";
		std::cout << Third3 / 100 + "tied, restarting team assignment\n";
		return;
	}
	DrawDone = true;
	Third = Third / 100;
	Third2 = Third2 / 100;
	Third3 = Third3 / 100;
	Third4 = Third4 / 100;
	printf("\n");
	switch (Third)
	{
	case 1:
		Players[0].Team = 1;
		printf("Player 1 and ");
		break;
	case 2:
		Players[1].Team = 1;
		printf("Player 2 and ");
		break;
	case 3:
		Players[2].Team = 1;
		printf("Player 3 and ");
		break;
	case 4:
		Players[3].Team = 1;
		printf("Player 4 and ");
		break;

	default:
		printf("This shouldnt happen");
	}
	switch (Third2)
	{
	case 1:
		Players[0].Team = 1;
		printf("Player 1 will be on team 1 \n");
		break;
	case 2:
		Players[1].Team = 1;
		printf("Player 2 will be on team 1 \n");
		break;
	case 3:
		Players[2].Team = 1;
		printf("Player 3 will be on team 1 \n");
		break;
	case 4:
		Players[3].Team = 1;
		printf("Player 4 will be on team 1 \n");
		break;

	default:
		printf("This shouldnt happen");
	}
	switch (Third3)
	{
	case 1:
		Players[0].Team = 2;
		printf("Player 1 and ");
		break;
	case 2:
		Players[1].Team = 2;
		printf("Player 2 and ");
		break;
	case 3:
		Players[2].Team = 2;
		printf("Player 3 and ");
		break;
	case 4:
		Players[3].Team = 2;
		printf("Player 4 and ");
		break;

	default:
		printf("This shouldnt happen");
	}
	switch (Third4)
	{
	case 1:
		Players[0].Team = 2;
		printf("Player 1 will be on team 2 \n");
		break;
	case 2:
		Players[1].Team = 2;
		printf("Player 2 will be on team 2 \n");
		break;
	case 3:
		Players[2].Team = 2;
		printf("Player 3 will be on team 2 \n");
		break;
	case 4:
		Players[3].Team = 2;
		printf("Player 4 will be on team 2 \n");
		break;

	default:
		printf("This shouldnt happen");
	}
}
void trumpdraw()
{
	std::cout << "\n" + InPlay.back().Name + " was selected as trump\n";
	Trump = InPlay.back().Suit;
	InPlay.pop_back();
}
void trumpdecide()
{

}
std::vector<Card> CreateCards()
{
	Card one;
	one.Value = 1;
	one.Suit = 1;
	one.Name = "Eight of Hearts";

	Card two;
	two.Value = 2;
	two.Suit = 1;
	two.Name = "Nine of Hearts";

	Card three;
	three.Value = 3;
	three.Suit = 1;
	three.Name = "Ten of Hearts";

	Card four;
	four.Value = 4;
	four.Suit = 1;
	four.Name = "Jack of Hearts";

	Card five;
	five.Value = 5;
	five.Suit = 1;
	five.Name = "Queen of Hearts";

	Card six;
	six.Value = 6;
	six.Suit = 1;
	six.Name = "King of Hearts";

	Card seven;
	seven.Value = 7;
	seven.Suit = 1;
	seven.Name = "Ace of Hearts";

	Card eight;
	eight.Value = 1;
	eight.Suit = 2;
	eight.Name = "Eight of Diamonds";

	Card nine;
	nine.Value = 2;
	nine.Suit = 2;
	nine.Name = "Nine of Diamonds";

	Card ten;
	ten.Value = 3;
	ten.Suit = 2;
	ten.Name = "Ten of Diamonds";

	Card eleven;
	eleven.Value = 4;
	eleven.Suit = 2;
	eleven.Name = "Jack of Diamonds";

	Card twelve;
	twelve.Value = 5;
	twelve.Suit = 2;
	twelve.Name = "Queen of Diamonds";

	Card thirteen;
	thirteen.Value = 6;
	thirteen.Suit = 2;
	thirteen.Name = "King of Diamonds";

	Card fourteen;
	fourteen.Value = 7;
	fourteen.Suit = 2;
	fourteen.Name = "Ace of Diamonds";

	Card fifteen;
	fifteen.Value = 1;
	fifteen.Suit = 3;
	fifteen.Name = "Eight of Clubs";

	Card sixteen;
	sixteen.Value = 2;
	sixteen.Suit = 3;
	sixteen.Name = "Nine of Clubs";

	Card seventeen;
	seventeen.Value = 3;
	seventeen.Suit = 3;
	seventeen.Name = "Ten of Clubs";

	Card eighteen;
	eighteen.Value = 4;
	eighteen.Suit = 3;
	eighteen.Name = "Jack of Clubs";

	Card nineteen;
	nineteen.Value = 5;
	nineteen.Suit = 3;
	nineteen.Name = "Queen of Clubs";

	Card twenty;
	twenty.Value = 6;
	twenty.Suit = 3;
	twenty.Name = "King of Clubs";

	Card twentyone;
	twentyone.Value = 7;
	twentyone.Suit = 3;
	twentyone.Name = "Ace of Clubs";

	Card twentytwo;
	twentytwo.Value = 1;
	twentytwo.Suit = 4;
	twentytwo.Name = "Eight of Spades";

	Card twentythree;
	twentythree.Value = 2;
	twentythree.Suit = 4;
	twentythree.Name = "Nine of Spades";

	Card twentyfour;
	twentyfour.Value = 3;
	twentyfour.Suit = 4;
	twentyfour.Name = "Ten of Spades";

	Card twentyfive;
	twentyfive.Value = 4;
	twentyfive.Suit = 4;
	twentyfive.Name = "Jack of Spades";

	Card twentysix;
	twentysix.Value = 5;
	twentysix.Suit = 4;
	twentysix.Name = "Queen of Spades";

	Card twentyseven;
	twentyseven.Value = 6;
	twentyseven.Suit = 4;
	twentyseven.Name = "King of Spades";

	Card twentyeight;
	twentyeight.Value = 7;
	twentyeight.Suit = 4;
	twentyeight.Name = "Ace of Spades";

	Player PlayerOne;
	PlayerOne.Team;
	PlayerOne.Name = "Player One";
	PlayerOne.Hand = Player1;

	Player PlayerTwo;
	PlayerTwo.Team;
	PlayerTwo.Name = "Player Two";
	PlayerTwo.Hand = Player2;

	Player PlayerThree;
	PlayerThree.Team;
	PlayerThree.Name = "Player Three";
	PlayerThree.Hand = Player3;

	Player PlayerFour;
	PlayerFour.Team;
	PlayerFour.Name = "Player Four";
	PlayerFour.Hand = Player4;

	Players.emplace_back(PlayerOne);
	Players.emplace_back(PlayerTwo);
	Players.emplace_back(PlayerThree);
	Players.emplace_back(PlayerFour);

	std::vector<Card> Cardss;
	Cardss.emplace_back(one);
	Cardss.emplace_back(two);
	Cardss.emplace_back(three);
	Cardss.emplace_back(four);
	Cardss.emplace_back(five);
	Cardss.emplace_back(six);
	Cardss.emplace_back(seven);
	Cardss.emplace_back(eight);
	Cardss.emplace_back(nine);
	Cardss.emplace_back(ten);
	Cardss.emplace_back(eleven);
	Cardss.emplace_back(twelve);
	Cardss.emplace_back(thirteen);
	Cardss.emplace_back(fourteen);
	Cardss.emplace_back(fifteen);
	Cardss.emplace_back(sixteen);
	Cardss.emplace_back(seventeen);
	Cardss.emplace_back(eighteen);
	Cardss.emplace_back(nineteen);
	Cardss.emplace_back(twenty);
	Cardss.emplace_back(twentyone);
	Cardss.emplace_back(twentytwo);
	Cardss.emplace_back(twentythree);
	Cardss.emplace_back(twentyfour);
	Cardss.emplace_back(twentyfive);
	Cardss.emplace_back(twentysix);
	Cardss.emplace_back(twentyseven);
	Cardss.emplace_back(twentyeight);
	return Cardss;
}

int main()
{
	std::vector<Card> Cardss = CreateCards();
	

	while (DrawDone == false)
	{
		InPlay = Cardss;
		randomizer();
		drawprint();
		PlayerTeams();
		printf("\n");
		InPlay = Cardss;
		randomizer();
		drawprint();
		drawprint();
		drawprint();
		drawprint();
		drawprint();
		trumpdraw();
		trumpdecide();
	}
	DrawDone = false;

	//Deal hands
	//Chose trump or not
	//
	//rank();
}