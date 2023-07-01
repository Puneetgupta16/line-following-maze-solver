void pathTrigCheck(){

if(final_run_var == 0){
  int temp_led_state ;
  if(led[0]<=50&&led[1]<=50&&led[2]<=50&&led[3]<=50&&led[4]<=50){
    temp_led_state = 1;
    }
  else{temp_led_state = 0;}
  if(led_path_left==1||led_path_right==1||(led_path_left==0&&led_path_front==0&&led_path_center==0&&led_path_right==0&&temp_led_state==1)){
      delay(del_point);
    if(algo_toggle_var == 0 )
      {
        LSRB();
      }
    if(algo_toggle_var == 1 )
      {
        RSLB();
      }
  }
}

if (final_run_var == 1){    //point is made 0 at final_run_var=1;
    if(way[point]=='L'){
      left();point++;
    }
    if(way[point]=='R'){
      right();point++;
    }
    if(way[point]=='S'){
      straight();point++;
    }
    if(way[point]=='B'){
      back();point++;
    }
    checkEndLeft();

}
}

void LSRB(){
    if(led_path_left == 0 && led_path_front == 0 && led_path_right == 0 ){digitalWrite(13,HIGH);
    path = 'B';back();way[point] = 'B'; point++;digitalWrite(13,LOW);
    }
    // if(led_path_left == 0 && led_path_front == 0 && led_path_right == 1 ){delay(3000 );
    if(led_path_left == 0 && led_path_front == 0 && led_path_right == 1 ){digitalWrite(13,HIGH);
    path = 'R';right();way[point] = 'R'; point++;digitalWrite(13,LOW);
    }
    if(led_path_left == 0 && led_path_front == 1 && led_path_right == 0 ){digitalWrite(13,HIGH);
    path = 'S';straight();way[point] = 'S'; point++;digitalWrite(13,LOW);
    }
    if(led_path_left == 0 && led_path_front == 1 && led_path_right == 1 ){digitalWrite(13,HIGH);
    path = 'Q';straight();way[point] = 'S'; point++;digitalWrite(13,LOW);
    }
    if(led_path_left == 1 && led_path_front == 0 && led_path_right == 0 ){digitalWrite(13,HIGH);
    path = 'L';left();way[point] = 'L'; point++;digitalWrite(13,LOW);
    }
    if(led_path_left == 1 && led_path_front == 0 && led_path_right == 1 ){digitalWrite(13,HIGH);
    path = 'T';left();way[point] = 'L'; point++;digitalWrite(13,LOW);
    }
    if(led_path_left == 1 && led_path_front == 1 && led_path_right == 0 ){digitalWrite(13,HIGH);
    path = 'P';left();way[point] = 'L'; point++;digitalWrite(13,LOW);
    }
    if(led_path_left == 1 && led_path_front == 1 && led_path_right == 1 ){digitalWrite(13,HIGH);    //check end left
    checkEndLeft();
    }
    LSRBalgo();
}
void RSLB(){
    if(led_path_left == 0 && led_path_front == 0 && led_path_right == 0 ){digitalWrite(13,HIGH);
    path = 'B';back();way[point] = 'B'; point++;digitalWrite(13,LOW);
    }
    if(led_path_left == 0 && led_path_front == 0 && led_path_right == 1 ){digitalWrite(13,HIGH);
    path = 'R';right();way[point] = 'R'; point++;digitalWrite(13,LOW);
    }
    if(led_path_left == 0 && led_path_front == 1 && led_path_right == 0 ){digitalWrite(13,HIGH);
    path = 'S';straight();way[point] = 'S'; point++;digitalWrite(13,LOW);
    }
    if(led_path_left == 0 && led_path_front == 1 && led_path_right == 1 ){digitalWrite(13,HIGH);
    path = 'Q';right();way[point] = 'R'; point++;digitalWrite(13,LOW);
    }
    if(led_path_left == 1 && led_path_front == 0 && led_path_right == 0 ){digitalWrite(13,HIGH);
    path = 'L';left();way[point] = 'L'; point++;digitalWrite(13,LOW);
    }
    if(led_path_left == 1 && led_path_front == 0 && led_path_right == 1 ){digitalWrite(13,HIGH);
    path = 'T';right();way[point] = 'R'; point++;digitalWrite(13,LOW);
    }
    if(led_path_left == 1 && led_path_front == 1 && led_path_right == 0 ){digitalWrite(13,HIGH);
    path = 'P';straight();way[point] = 'S'; point++;digitalWrite(13,LOW);
    }
    if(led_path_left == 1 && led_path_front == 1 && led_path_right == 1 ){digitalWrite(13,HIGH);    //check end right
    checkEndRight();
    }
    RSLBalgo();
}

void LSRBalgo(){
  for(int i = 0; i <= point + 5; i++){

    if(way[i] == 'B'){

       if(way[i-1]=='L'&&way[i]=='B'&&way[i+1]=='R'){
          way[i-1] = 'B';point--;point--;
       }
       if(way[i-1]=='L'&&way[i]=='B'&&way[i+1]=='S'){
          way[i-1] = 'R';point--;point--;
       }
       if(way[i-1]=='R'&&way[i]=='B'&&way[i+1]=='L'){
          way[i-1] = 'B';point--;point--;
       }
       if(way[i-1]=='S'&&way[i]=='B'&&way[i+1]=='L'){
          way[i-1] = 'R';point--;point--;
       }
       if(way[i-1]=='S'&&way[i]=='B'&&way[i+1]=='S'){
          way[i-1] = 'B';point--;point--;
       }
       if(way[i-1]=='L'&&way[i]=='B'&&way[i+1]=='L'){
          way[i-1] = 'S';point--;point--;
       }
    }

  }
}

void RSLBalgo(){
  for(int i = 0; i <= point + 5; i++){

    if(way[i] == 'B'){

       if(way[i-1]=='R'&&way[i]=='B'&&way[i+1]=='L'){
          way[i-1] = 'B';point--;point--;
       }
       if(way[i-1]=='R'&&way[i]=='B'&&way[i+1]=='S'){
          way[i-1] = 'L';point--;point--;
       }
       if(way[i-1]=='L'&&way[i]=='B'&&way[i+1]=='R'){
          way[i-1] = 'B';point--;point--;
       }
       if(way[i-1]=='S'&&way[i]=='B'&&way[i+1]=='R'){
          way[i-1] = 'L';point--;point--;
       }
       if(way[i-1]=='S'&&way[i]=='B'&&way[i+1]=='S'){
          way[i-1] = 'B';point--;point--;
       }
       if(way[i-1]=='R'&&way[i]=='B'&&way[i+1]=='R'){
          way[i-1] = 'S';point--;point--;
       }
    }

  }
}