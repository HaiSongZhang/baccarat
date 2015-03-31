#include <iostream>
#include <algorithm>

using namespace std;
int main(void)
{
	int numberOfGame = 0;
	double startingAmount =0;
	double bettingAmount =0;
	bool choice =0;
	
	cout<<"max game you can play is 52 games"<<endl;
	
	cout<<"please input starting amount : ";
	cin>>startingAmount;
	cout<< "please input minimum betting : ";
	cin>> bettingAmount;
	cout<< "which side would you like to pick? 0 for banker, 1 for player : ";
	cin>>choice;
	
	
	// I assuming there are 6 decks for a table
	int card[312];
	int counter = 0;
	int oneSet [13] = {1,2,3,4,5,6,7,8,9,0,0,0,0};
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<4; j++)
		{
			for(int k=0; k<13; k++)
			{
				card[counter] = oneSet[k];
				counter++;
			}
		}
	}
	
	//shuffling the cards
	random_shuffle(&card[0], &card[312]);
	
	cout<<"----------------------------------"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"----------------------------------"<<endl;
	
	cout<< "game start!!"<<endl;
	double originalBatting = bettingAmount;
	int hands = 0;
	//case the player chooses banker
	if(choice == 0)
	{
		for(int i=0; i<52; i++)
		{
			int player=0;
			int banker=0;
			
			//Each players get cards
			
			player += card[hands];
			hands++;
			banker += card[hands];
			hands++;
			player += card[hands];
			hands++;
			banker += card[hands];
			hands++;
			
			//check only the last digits
			player = player%10;
			banker = banker%10;
			
			cout<< "player is "<< player <<" banker is "<<banker<< "--->";
			
			if(player <=5)
			{
				player += card[hands];
				hands++;
				player = player%10;
			}
			//case when player is not 8 or nine
			if(player !=8 || player !=9)
			{
				switch(banker)
				{
					case 1:
						banker += card[hands];
						hands++;
						banker = banker%10;
						break;
					case 2:
						banker += card[hands];
						hands++;
						banker = banker%10;
						break;
					case 3:
						banker += card[hands];
						hands++;
						banker = banker%10;
						break;
					case 4: 
						if(player !=0 || player !=1 || player !=8 || player !=9 )
						{
							banker += card[hands];
							hands++;
							banker = banker%10;
							break;
						}
					case 5:
						if(player ==4 || player ==5 || player ==6 || player ==7)
						{
							banker += card[hands];
							hands++;
							banker = banker%10;
							break;
						}
				}
			}
			
			
			//compare player and banker's value
			if(player>banker)
			{
				startingAmount -= bettingAmount;
				bettingAmount *= 2;
				cout<<"lose "<<" your balance is "<<startingAmount<<endl;
				
			}
			if(player==banker)
			{
				cout<<"tie"<<endl;
			}
			if(player<banker)
			{
				startingAmount += (bettingAmount*0.95);
				bettingAmount = originalBatting;
				cout<<"win "<<" your balance is "<<startingAmount<<endl;
			}
			
			if(startingAmount<0)
			{
				cout<<"you do not have money any more....";
				break;
			}
		}
	}
	
	//case the plater chooses player
	else
	{
		for(int i=0; i<52; i++)
		{
			int player=0;
			int banker=0;
			
			//Each players get cards
			
			player += card[hands];
			hands++;
			banker += card[hands];
			hands++;
			player += card[hands];
			hands++;
			banker += card[hands];
			hands++;
			
			//check only the last digits
			player = player%10;
			banker = banker%10;
			
			cout<< "player is "<< player <<" banker is "<<banker<< "--->";
			
			if(player <=5)
			{
				player += card[hands];
				hands++;
				player = player%10;
			}
			//case when player is not 8 or nine
			if(player !=8 || player !=9)
			{
				switch(banker)
				{
					case 1:
						banker += card[hands];
						hands++;
						banker = banker%10;
						break;
					case 2:
						banker += card[hands];
						hands++;
						banker = banker%10;
						break;
					case 3:
						banker += card[hands];
						hands++;
						banker = banker%10;
						break;
					case 4: 
						if(player !=0 || player !=1 || player !=8 || player !=9 )
						{
							banker += card[hands];
							hands++;
							banker = banker%10;
							break;
						}
					case 5:
						if(player ==4 || player ==5 || player ==6 || player ==7)
						{
							banker += card[hands];
							hands++;
							banker = banker%10;
							break;
						}
				}
			}
			
			
			//compare player and banker's value
			if(player>banker)
			{
				startingAmount += bettingAmount;
				bettingAmount = originalBatting;
				cout<<"win "<<" your balance is "<<startingAmount<<endl;
				
			}
			if(player==banker)
			{
				cout<<"tie"<<endl;
			}
			if(player<banker)
			{		
				startingAmount -= bettingAmount;
				bettingAmount *= 2;
				cout<<"lose "<<" your balance is "<<startingAmount<<endl;
			}
			
			if(startingAmount<0)
			{
				cout<<"you do not have money any more....";
				break;
			}
		}
	}
	
	
}