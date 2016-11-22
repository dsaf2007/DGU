#include <iostream>

#define MAX2(a, b)                  ((a)>(b) ? (a):(b))
#define MAX3(a, b, c)                (MAX2(MAX2(a,b),(c)))
#define MAX4(a, b, c, d)              (MAX2(MAX3(a,b,c),(d)))

class Celldata
{
public:
	double q_[4] = { 0.0,0.0,0.0,0.0 };    //up,down,left,right
	double reward_ = 0.0;

	Celldata()
	{}

	double GetMaxQ()
	{
		return MAX4(q_[0], q_[1], q_[2], q_[3]);
	}

};

class GridWorld
{
public:
	int i_res_, j_res_;
	Celldata *q_arr2d_ = nullptr;
	
	GridWorld(const int& i_res, const int& j_res)
	{
		i_res_ = i_res; j_res_ = j_res;

		q_arr2d_ = new Celldata[i_res*j_res];
	}

	Celldata& getcell(const int& i, const int& j)
	{
		return q_arr2d_[i + i_res_*j];
	}
	bool isInside(const int& i, const int& j)
	{
		if (i < 0)return false;
		if (i >= i_res_)return false;

		if (j < 0)return false;
		if (j >= j_res_)return false;

		return true;
	}

	void printSigned(const float& v)
	{
		if (v > 0.0f) printf("+%1.1f", v);
		else if (v < 0.0f)printf("%1.1f", v);
		else
			printf(" 0.0f");
	}

	void print()
	{
		for (int j = j_res_ - 1; j >= 0; j--)
		{
			for (int i = 0; i < i_res_; i++)
			{
				Celldata &cell = getcell(i, j);

				printf("   "); printSigned(cell.q_[0]); printf("   ");//up
				printf("   ");
			}
			printf("\n");

			for (int i = 0; i < i_res_; i++)
			{
				Celldata &cell = getcell(i, j);


				printSigned(cell.q_[2]); printf("   "); printSigned(cell.q_[3]);//up
				printf("   ");

			}
			printf("\n");
			for (int i = 0; i < i_res_; i++)
			{
				Celldata &cell = getcell(i, j);

				printf("   "); printSigned(cell.q_[1]); printf("   ");//up
				printf("   ");
			}

			printf("\n\n");
		}
	}
};
class Agent
{
public:
	int i_, j_;    //position in grid world
	double reward_;  //reward sum

	Agent()
		:i_(0), j_(0), reward_(0.0)
	{}

};
void main()
{
	std::cout << "hello,grid world!" << std::endl;

	const int world_res_i = 3, world_res_j = 2;

	GridWorld world(world_res_i, world_res_j);
	//for (int j = 0; j < world_res_j; j++)
	//	for (int i = 0; i < world_res_i; i++)
	//	{
	//		world.getcell(i, j).reward_ = -0.1;
	//	}


	world.getcell(2, 1).reward_ = 1.0;
	world.getcell(2, 0).reward_ = -1.0f;

	Agent my_agent;

	

	world.print();

	for (int t = 0; t < 1000000; t++)
	{
		const int action = rand() % 4;

		int i = my_agent.i_, j = my_agent.j_;
		int i_old = i, j_old = j;
		
		switch (action)
		{
		case 0:
			j++;
			break;
		case 1:
			j--;
			break;
		case 2:
			i--;
			break;
		case 3:
			i++;
			break;
		}

		if (world.isInside(i, j) == true)
		{
			my_agent.i_ = i; my_agent.j_ = j;//move agent

			if(my_agent.i_=2)
			{ 
				if(my_agent.j_=1){
			world.getcell(i_old,j_old).reward_=//update reward(r_t)
			//update q values of previous cell(q_t)
			//reset if agent is in final cells
		}
		else
		{
			//you may give negative reward (penalty) to agent
		}
	}


	std::cout<<std::endl;
	world.print();

}