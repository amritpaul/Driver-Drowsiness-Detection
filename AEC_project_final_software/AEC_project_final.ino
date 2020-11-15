
 int timer = 500;           // 0.5 secs timer variable

void setup() {Serial.begin(9600);
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 1; thisPin < 14; thisPin++)  {
    pinMode(thisPin, OUTPUT);
  }
}

void loop()
{
  int flag=0,block=0,l=0,u=0,d=0,valid=0,maximum=0; //variable for indication of loop breaking
 int a=analogRead(5);int i; //reads sensor input
 Serial.println(a);
  //indication for personalisation
 digitalWrite(2,HIGH);
      delay(timer*4);
      digitalWrite(2,LOW);
  //   personalisation begins
  {
   for(i=1;i<=2000;i++)
  {
    int a=analogRead(5); //reads sensor input
 Serial.println(a);
 if(a>505 && block==0)
 {
   
   block=1; //reading starts
   l=i; // iteration counter
   
 }
 else if(a>505 && block==1) //skips extra readings due to speed of program
 u=i;
 else
 {
   block=0;
   if((u-l)>maximum)
   maximum=u-l; // calculates the maximum blink duration
 }
  } 
  }
  
  // indication for personalisation to end
 digitalWrite(2,HIGH);
      delay(timer*4);
      digitalWrite(2,LOW);
delay(timer*3);
i=0;   // variable used for iteration count of readings
// working value is variable maxiimum  
  //checking construct main woring body of the program
  while (true)  //infinite loop is being used for continuous computation
  {
    i++;  // counter per reading
        int a=analogRead(5); //reads sensor input
 Serial.println(a);
 // validity checking constructs
 if(a>505 && block==0)
 {
   l=i;
   block=1;
 }
 else if(a>505 && block==1) //checks end of blinking reading density
 {
   u=i;
   if((u-l)>maximum+200)// if eye remains continuously closed
   valid=1;
}
 else //....condition for checking true conditions..
 {
   block=0;  //indicator variable
   if((u-l)>maximum+200)// ....main condition of the program...
   valid=1;
 }
    //tasking construct begins
    if(valid==1 && flag==0) //condition of first emergency
    {
      flag=1;
      digitalWrite(3,HIGH); // launches LED and launches buzzer
      delay(timer*3);
      digitalWrite(3,LOW);
      valid=0;u=0;u=l;  //re initialisation
    }
    //condition for second emergency
   else if(valid==1 && flag==1)
    {
      digitalWrite(4,HIGH); // launches LED 2 to glow
      digitalWrite(3,HIGH); // launches brake servo
      delay(timer*2);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      delay(timer*1000); //substantial delay of 8.3 minutes 
      // end of program
    }
    } 
  }


