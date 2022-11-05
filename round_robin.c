// C++ code
// ROGIMIE B. DANILA BSCPE-4A
// ACTIVITY 6 - RR
// ROUND ROBIN
//
/*
Process ID			Arrival Time		Burst Time
Pin 1				0000mm				5000mm
Pin 2				5000mm				2000mm
Pin 3				2000mm				6000mm
Pin 4				4000mm				3000mm
Pin 5				6000mm				1000mm
Pin 6				8000mm				9000mm
Pin 7				7000mm				7000mm
Pin 8				1000mm				4000mm
Time Quantum = 2000 milliseconds
*/

void setup()
{
  pinMode(10, OUTPUT); //set port 10 to output
  pinMode(9, OUTPUT); //set port 9 to output
  pinMode(8, OUTPUT); //set port 8 to output
  pinMode(7, OUTPUT); //set port 7 to output
  pinMode(6, OUTPUT); //set port 6 to output
  pinMode(5, OUTPUT); //set port 5 to output
  pinMode(4, OUTPUT); //set port 4 to output
  pinMode(3, OUTPUT); //set port 3 to output
}

void loop()
{
  round_robin(); //calling out the delay round robin function
}

void round_robin()
{
  int time_quantum = 2000;
  int burst_time[8] = {5000, 2000, 6000, 3000, 1000, 9000, 7000, 4000};
  //an array of time in milliseconds to be used in delay rr function
  int pin [8] = {10, 9, 8, 7, 6, 5, 4, 3};
  int ready_queue[8];
  int arrival_time[8] = {0000, 5000, 2000, 4000, 6000, 8000, 7000, 1000};
  int time = 0;
  
  int temp; //temporary value
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (arrival_time[i] < arrival_time[j])
      {
        temp = arrival_time[i];
        arrival_time[i] = arrival_time[j];
        arrival_time[j] = temp;
        temp = burst_time[i];
        burst_time[i] = burst_time[j];
        burst_time[j] = temp;
        temp = pin[i];
        pin[i] = pin[j];
        pin[j] = temp;
      }
    }
  } // executes loop
  
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(pin[i], HIGH);
    delay(time_quantum);
    digitalWrite(pin[i], LOW);
    burst_time[i] = burst_time[i] - time_quantum;
  }
}//executes round robin
