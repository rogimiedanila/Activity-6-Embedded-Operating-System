// C++ code
// ROGIMIE B. DANILA BSCPE-4A
// ACTIVITY 6 - FIFO
//
void setup()
{
  pinMode(10, OUTPUT); //set port 10 to output
  pinMode(9, OUTPUT); //set port 9 to output
  pinMode(8, OUTPUT); //set port 8 to output
  pinMode(7, OUTPUT); //set port 7 to output
  pinMode(6, OUTPUT);//set port 6 to output
  pinMode(5, OUTPUT); //set port 5 to output
  pinMode(4, OUTPUT); //set port 4 to output
  pinMode(3, OUTPUT); //set port 3 to output
}

void loop()
{
  first_in_first_out(); //calling out the delay fifo function 
}

void first_in_first_out()
{
  int time [8] = {5000, 2000, 6000, 3000, 1000, 9000, 7000, 4000};
  //an array of time in milliseconds to be used in delay fifo function
  int count = 0; //used to identifies the element of time array.
  
  for (int i = 10; i >= 3; i--)
  {
    digitalWrite(i, HIGH); // turn the LED on
    delay (time[count]); //delay
    digitalWrite(i, LOW); //turn the LED off
    count++; //increment
  }
}
