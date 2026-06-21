Task 1 — Variables & Serial
1. What is the difference between int and float? Give one example of when you would use each.
int is a data type used to store whole numbers (integers) without any decimal points, whereas float is used to store numbers that have a decimal point (fractional numbers).
For example, I would use an int to store the number of times an LED has blinked (e.g., int blinkCount = 5;), and a float to store a precise temperature reading from an analog sensor (e.g., float temp = 36.5;).

3. What happens if you forget to write Serial.begin(9600) in setup()? Try it and explain what you observe.
If Serial.begin(9600) is omitted, the Arduino fails to establish a serial communication link with the computer at the specified baud rate.
When opening the Serial Monitor, it was completely blank.

5. Why does the output appear only once and not over and over?
The output appears only once because the Serial.print() commands were written inside the setup() function.
The setup() function is specifically designed by the Arduino environment to run exactly one time when the board is powered on or reset.
If the commands were placed in the loop() function, they would repeat indefinitely.


Task 2 — Your First Blink — Using Variables
1. Why do we put pinMode(ledPin, OUTPUT); inside setup() and not inside loop()?
We place pinMode(ledPin, OUTPUT); inside setup() because configuring a specific pin to behave as an output is an initialization step that only needs to happen once.
If placed inside loop(), the Arduino would repeatedly reconfigure the pin during every cycle, which is inefficient and unnecessary.

3. What would happen if we removed both delay() calls? Predict first, then try it and describe what you actually see.
Prediction: The LED will cycle between HIGH and LOW so rapidly that it will look like it is constantly turned on.
Observation: As predicted, the LED appears to stay on. The microcontroller executes the on and off instructions in fractions of a millisecond, which is much faster than the human eye can perceive, creating the illusion of a continuous glow.

4. If you wanted the LED to be ON for 3 seconds and OFF for half a second, which values would you change and to what?
Assuming variables are used for the delays, I would change the ON delay variable's value to 3000 (which corresponds to 3000 milliseconds or 3 seconds) and the OFF delay variable's value to 500 (which corresponds to 500 milliseconds or 0.5 seconds).


Task 3 — Make It a Function
1. In your own words, explain what a parameter is. (Hint: waitTime in our example.)
A parameter is a placeholder variable declared in a function's definition. It allows you to pass specific values (arguments) into the function when you call it, so the function can perform its task based on the input provided, making the code much more flexible and reusable.

2. Why is it useful to put repeating code into a function instead of writing it three times in loop()?
Putting repeating code into a function prevents code duplication, which keeps the overall program concise, organized, and easier to read. Additionally, if you need to fix a bug or change the behavior of that repeated code, you only need to modify it in one place (inside the function).

3. Could you write blinkOnce without taking any parameter at all? If yes, how would you make it blink at different speeds without parameters?
Yes, blinkOnce() can be written without parameters. To make it blink at different speeds without parameters, you could define a global variable to control the delay time and update that global variable right before each function call. Alternatively, you could create separate functions for different speeds (like blinkFast() and blinkSlow()). However, using a parameter is generally a much cleaner and more modular approach.


Task 4 — Count Down with a while Loop

1. What is the role of the line counter = counter - 1; ? What would happen without it?
The line counter = counter - 1; decrements the loop's control variable by 1 on each iteration. Without it, the counter would never decrease, meaning the loop's condition (e.g., counter > 0) would always evaluate to true. This would result in an infinite loop, causing the program to get stuck running the same block of code forever.

2. Rewrite the countdown to start from 7 instead of 5. (Paste just the changed lines in your report.)

int counter = 7;
while (counter > 0) {
  Serial.println(counter);
  counter = counter - 1;
  delay(1000);
}

3. In your own words, what is the difference between setup() and a while loop? They both run code — what makes them different?
setup() is a core Arduino function that automatically runs exactly once when the microcontroller starts up.
A while loop, on the other hand, is a programming control structure that can be placed anywhere in the code. It runs a specific block of code repeatedly as long as a defined condition remains true, and stops when the condition becomes false.


Task 5 — Putting It All Together — Smart Countdown
1. Paste your final, working code.

        //Setting Up Variables
        int startValue = 5;
        int ledPin = 13;
        
        //Fucntion For Flashing Led The Desired Number Of Times
        void flashLED(int times) {
          for(int i = 0; i < times; i++){
            digitalWrite(ledPin, HIGH); // LED ON
            delay(150);
            digitalWrite(ledPin, LOW); // LED OFF
            delay(150);
          }
        }
      
        //Setup Function: Runs Once After Upload
        void setup(){
        
        pinMode(ledPin, OUTPUT);//Pin Output Setup
        
        Serial.begin(9600);//Serial Monitor Initialization
        
        Serial.println("  ");
        Serial.println("=== Smart Countdown Starting ===");
        int count = startValue;
        while (count != 0){
          Serial.print("Count: ");
          Serial.println(count);
          flashLED(6); //flashes or blinks LED, Pin 13
          delay(1000);
          count = count - 1;
        }
        Serial.println("=== Countdown Complete ===");
        }
      
        //void function: Runs On Repeat After Upload
        void loop(){
      
       }

3. Describe one bug or mistake you ran into while writing this program and how you fixed it. (Be honest. Everyone runs into bugs.)
While writing the flashLED function, I initially forgot to specify the data type for the parameter and wrote `void flashLED(times)` instead of `void flashLED(int times)`.
This resulted in a compilation error. I fixed the bug by adding the `int` keyword to properly declare the parameter type.

5. If you wanted the program to count DOWN by 2 each step (5, 3, 1) instead of by 1, what would you change?
I would modify the decrement statement inside the while loop from `count = count - 1;` to `count = count - 2;`.

6. If you wanted the LED to also stay ON for a final 5 seconds after the countdown completes, where in the code would you add this and what would the code look like?
I would add the code directly after the while loop concludes in the setup() function, right after the final Serial.println() statement. The addition would look like this:

  digitalWrite(ledPin, HIGH);
  delay(5000);
  digitalWrite(ledPin, LOW);
