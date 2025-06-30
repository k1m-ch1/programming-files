String data_recv = "";

int temp_array[6];  //Stores the index of comma
int list_of_values[5];  //Stores the numbers at each comma
int correspond_pins[5] = {11,10,9,6,5}; //

int char_to_int(char my_char); // Converts a char data type into an int if possible
int string_to_int(String my_string); // converts a string data type into an int if possible
void string_index(char target, String temp_string); // Changes data of temp_array in the global scope, returns null.
void get_values(String temp_string); // Changes data of list_of_values in the global schope, returns null.
void print_to_serial(); // Print from list_of_values to serial monitor

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(5);
  attachInterrupt(digitalPinToInterrupt(2), print_to_serial, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    data_recv = Serial.readString();
    string_index(',', data_recv);
    get_values(data_recv);
    for (int i = 0; i < 5; i++){
      analogWrite(correspond_pins[i], list_of_values[i]);
    }
    data_recv="";
  }
}


int char_to_int(char my_char){
  int ret_val = ((int)my_char - 48);
  if (ret_val < 0 || ret_val >= 10){
    return 0;
  }else{
    return ret_val;};
}

int string_to_int(String my_string){
  int sum = 0;
  for (int i = 0; i < my_string.length(); i++){
    sum = sum + (char_to_int(my_string[i]) * pow(10, (my_string.length()-i-1)));
  }
  return sum;
}

void string_index(char target, String temp_string){
  int current_index = 0;
  for (int i = 0; i < temp_string.length(); i++){
    if(temp_string[i] == target){
      temp_array[current_index] = i;
      current_index++;
    }
  }
}

void get_values(String temp_string) // Changes data of list_of_values in the global schope, returns null.
{
  String sub_string;
  for (int i = 0; i < 5;i++){
    sub_string = temp_string.substring(temp_array[i]+1, temp_array[i+1]);
    list_of_values[i] = string_to_int(sub_string);
    sub_string = "";
  }
}

void print_to_serial() // Print from list_of_values to serial monitor
{
  for (int i = 0; i < 5; i++){
    Serial.print(list_of_values[i]);
    Serial.print(" ");
  }
Serial.println();
}

