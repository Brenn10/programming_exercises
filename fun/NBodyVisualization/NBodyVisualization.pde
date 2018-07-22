
BufferedReader reader;
String[] lines;
void setup()
{
  //Initial setup of size and background
  frameRate(200); //fast
  background(255); //set to white to allow for blurred tails
  size(1280,1280); //set size
  reader=createReader("out.txt");//open file reader
  String line=""; //initialize line to be empty
  
  //Attempt to read first line
  try 
  { 
    line = reader.readLine(); //takes the first line that contains  
  } 
  catch (IOException e) 
  { 
    print("Bad Input File"); //if problems arise
  }
  
  //create list of lines
  ArrayList<String> linesList = new ArrayList<String>();
  
  //attempt to read each line and save to the lines list
  try
  {
    while(line!=null) //for each line
    {
      line = reader.readLine();//get line
      linesList.add(line); //add to list
    }
  }
  catch (IOException e) {} //handle bad line
  
  
  lines = new String[linesList.size()]; //create array for lines
  for(int i =0; linesList.size() > 0; i++) //for each thing in arraylist
  {
     lines[i] = linesList.remove(0); //add to the array
  }
  
  noStroke(); //do not do outlines
}

int counter=0; //counter for line
void draw()
{
  //fill background with black transparency for tails
  fill(0,20); 
  rect(0,0,width,height);
  
  //get current line
  String line=lines[counter];
  
  //end of file, done
  if (line == null) 
  {
    // End of file
    noLoop();  
  } 
  else 
  {
    String[] t_and_objects = split(line, "|"); //get each body and time
    String t = t_and_objects[0]; //get time
    
    //create time box and print time
    fill(0);
    rect(0,0,400,120);
    fill(255);
    textSize(100);
    text(t,0,100);
    
    //go through each segment
    for(int i =1; i < t_and_objects.length; i++)
    {
      //get each objects position
      String[] obj = split(t_and_objects[i],",");
      
      //draw object
      ellipse(float(obj[1])*50+width/2,float(obj[2])*50+height/2,5,5);
    }
  }
  
  //increment line counter
  counter+=1;
  
  //if counter past lines length, end program
  if(counter > lines.length)
    noLoop();
}

void mousePressed()
{
  //pause and save screen
  noLoop();
  save("screenshot.png");
}

void mouseReleased()
{
  //resume
  loop();
}