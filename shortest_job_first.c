// C++ code
// ROGIMIE B. DANILA BSCPE-4A
//ACTIVITY 6 - SJF
//SHORTEST JOB SCHEDULING ASSOCIATES WITH EACH PROCESS THE LENGTH OF THE PROCESS NEXT CPU BURST
//
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
  shortest_job_first(); // calling out the delay sjf function.
}

void shortest_job_first(){
  int pin[8] = {10, 9, 8, 7, 6, 5, 4, 3};
  int time[8] = {5000, 2000, 6000, 3000, 1000, 9000, 7000, 4000};
  //an array of time in milliseconds to be used in delay function.
  //Pin 1 has a time of 5 seconds.
  //Pin 2 has a time of 2 seconds.
  //Pin 3 has a time of 6 seconds.
  //Pin 4 has a time of 3 second.
  //Pin 5 has a time of 1 seconds.
  //Pin 6 has a time of 9 seconds.
  //Pin 7 has a time of 7 seconds.
  //Pin 8 has a time of 4 seconds.
  //With the given burst time, the first to be executed is the Pin 5 followed by Pin 2, Pin 4, Pin 8, Pin 1, Pin 3, Pin 7, and Pin 6.
  
  int temp; //temporary value used for swapping.
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if (time[i] < time[j]){
      	temp = time[i];
        time[i] = time[j];
        time[j] = temp;
        temp = pin[i];
        pin[i] = pin[j];
        pin[j] = temp;
      }
    }
  }
  //after executing this loop, the time array as well as pin array will be sorted in ascending.
  
  int count = 0; //used to identifies the element of time array.
  while (count != 8){
  	digitalWrite(pin[count], HIGH);
    delay(time[count]);
    digitalWrite(pin[count], LOW);
    count++;
  }
  //executes shortest job scheduling.
}
