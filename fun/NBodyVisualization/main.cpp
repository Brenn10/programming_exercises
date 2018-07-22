#include <cstdlib>
#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


#define PI          3.141592653589793238462643383279502884L /* pi */
#define G			( 4 * PI * PI)

using namespace std;

struct Dims {
	double x,y,z;
};

struct Body {



	//distance in AU
	//vel in AU/year
	//mass in solar mass
	Dims p,v; //position and velocity
	double mass;
	int id;
};

/**
 * Tokenizes one string into a vector of strings
 * @param str String to be tokenized
 * @param delimiter String describing location of split between tokens
 * @return Returns vector containing string tokens
 * @author Hunter Damron Original algorithm
 * @author Brennan Cain ADDED THE NEWLINE BRACES and comments
 */
vector<string> tokenize(string str, string delimiter) 
{
    vector<string> tokens;
    int start = 0;
    int end = 0;
    while (end != string::npos) //while not at the end
    {
        end = str.find(delimiter, start);//find the next instance of deliminator
        string sub = str.substr(start, end - start); //get the string till that point
        if (sub.size() > 0) //if not double of deliminator
        {
            tokens.push_back(sub); //push to vector
        }
        start = end + delimiter.size();
    }
    return tokens;
}

/**
 * Find the acceleration in each component of the vector for a body
 *
 * @param b a body to find accelerations on
 * @param bodies list of bodies to use in calculations
 *
 * @return Dims struct of the accelerations broken into components
*/
Dims getAttraction(Body b, vector<Body> bodies)
{
	Dims a; //struct to hold accelerations
	
	//initialize all accelerations to 0
	a.x=0;
	a.y=0;
	a.z=0;
	
	//Go through each body in the list
	for(int i =0; i < bodies.size(); i++)
	{
		if(bodies[i].id!=b.id) //if the body is not the same as the body in the list
		{
			//find the dist in each component
			double distx=b.p.x-bodies[i].p.x;
			double disty=b.p.y-bodies[i].p.y;
			double distz=b.p.z-bodies[i].p.z;

			//find the total distance
			float dist=sqrt(pow(distx,2)+pow(disty,2)+pow(distz,2));

			//find accerelation due to gravity on body
			double aM = G*bodies[i].mass/pow(dist,2);

			//break the aM into components
			a.x-=distx*aM/dist;
			a.y-=disty*aM/dist;
			a.z-=distz*aM/dist;
		}
	}
	//return the dims struct
	return a;
}

/**
 * Moves each body in the list and returns the new list
 *
 * @param bodies list of bodies in the simulation
 * @param dt time step
 *
 * @return new list of bodies
*/
vector<Body> move(vector<Body> bodies, double dt)
{
	vector<Body> newBodies(bodies.size());
	for(int i =0; i < bodies.size(); i++)
	{
		//Get the initial acceleration
		Dims ai = getAttraction(bodies[i],bodies);

		//get the initial position of the body
		Dims oldPos=bodies[i].p;

		//Find new position of body
		bodies[i].p.x=bodies[i].p.x+bodies[i].v.x*dt+ai.x*dt*dt/2.0;
		bodies[i].p.y=bodies[i].p.y+bodies[i].v.y*dt+ai.y*dt*dt/2.0;
		bodies[i].p.z=bodies[i].p.z+bodies[i].v.z*dt+ai.z*dt*dt/2.0;

		//get new acceleration
		Dims af = getAttraction(bodies[i],bodies);

		//finds the new velocity of the body
		bodies[i].v.x=bodies[i].v.x+(af.x+ai.x)*dt/2.0;
		bodies[i].v.y=bodies[i].v.y+(af.y+ai.y)*dt/2.0;
		bodies[i].v.z=bodies[i].v.z+(af.z+ai.z)*dt/2.0;

		//create a new body using new position, velocity, id and mass
		Body newBody;
		newBody.p= bodies[i].p;
		newBody.v=bodies[i].v;
		newBody.mass=bodies[i].mass;
		newBody.id=bodies[i].id;
		
		//add the new Body to the list of new bodies		
		newBodies[i]= newBody;
		
		//revert the body's position to the original to prevent adding energy by moving each individually
		bodies[i].p=oldPos;
	}
  
	//return the new bodies list
	return newBodies;
}

/**
 * Runs the simulation
 *
 * @param inFile File name of input file
 * @param outFile File name of output file
*/
void simulate(string inFile,string outFile)
{
	//Open Files
	ifstream in(inFile,ios::in);
	ofstream out(outFile,ios::out);
	
	//Variables to be used throughout
	double elapsedTime; //time to conduct simulation over
	double dt;//also known as timestep
	vector<Body> bodies; //vector of all bodies
	
	//Load elasped time
	string elapsedTimeString;
	getline(in,elapsedTimeString);
	elapsedTime = stod(elapsedTimeString);
	
	//Load time step
	string dTString;
	getline(in,dTString);
	dt = stod(dTString);
	
	
	//Go through objects until EOF
	while(!in.eof())
	{
		//declare and get line as a string
		string lineString;
		getline(in,lineString);
		
		//if empty line, continue
		if(lineString=="")//prevent seg faults
			continue;
		
		//convert line to a vector
		vector<string> line = tokenize(lineString,",");
		
		//create a new body from the line
		Body b;
		b.id=stod(line[0]);
		b.mass=stod(line[1]);
		b.p.x=stod(line[2]);
		b.p.y=stod(line[3]);
		b.p.z=stod(line[4]);
		b.v.x=stod(line[5]);
		b.v.y=stod(line[6]);
		b.v.z=stod(line[7]);
		
		//push the body to the list
		bodies.push_back(b);
	}
	
	//output the id and mass of each body
	for(auto b : bodies)
	{
		out << b.id << "," << b.mass << "|";
	}
	out << endl;
	
	//buffer to save to rather than file
	//stringstream buffer;
	
	//Go through the time of the simulation
	for(double t = 0; t <= elapsedTime; t+=dt)
	{
		out << t; //output the time
		for(auto b : bodies) //output each body seperated by bars
		{
			out<< "|" << b.id<<","<<b.p.x<<","<<b.p.y<<","<<b.p.z;
		}
		//output end of line
		out<<endl;
		
		//move everything
		bodies = move(bodies,dt);
	}
	
	
	//Close Files
	in.close();
	out.close();
}

int main(int argc,char** argv)
{
	if(argc==1) //only arg is command
	{
		simulate("in.txt","out.txt");
	}
	else if(argc == 2)//has input filename
    {
    	simulate(argv[1], "out.txt");
    }
    else if(argc == 3) //has input and output filename
    {
        simulate(argv[1], argv[2]);
    }
    else //error in number of arguments
    {
        cerr <<"Too many arguments."<<endl;
		exit(EXIT_FAILURE);
    }
	return 0;
}