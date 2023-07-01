void pathTrigCheck(){

if(final_run_var == 0){

  if(led_path_left==1||led_path_right==1||led_path_center==0){
    digitalWrite(13, HIGH);
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
    if(led_path_left == 0 && led_path_front == 0 && led_path_right == 0 ){
    path = 'B';back();way[point] = 'B'; point++;
    }
    if(led_path_left == 0 && led_path_front == 0 && led_path_right == 1 ){
    path = 'R';right();way[point] = 'R'; point++;
    }
    if(led_path_left == 0 && led_path_front == 1 && led_path_right == 0 ){
    path = 'S';straight();way[point] = 'S'; point++;
    }
    if(led_path_left == 0 && led_path_front == 1 && led_path_right == 1 ){
    path = 'Q';straight();way[point] = 'S'; point++;
    }
    if(led_path_left == 1 && led_path_front == 0 && led_path_right == 0 ){
    path = 'L';left();way[point] = 'L'; point++;
    }
    if(led_path_left == 1 && led_path_front == 0 && led_path_right == 1 ){
    path = 'T';left();way[point] = 'L'; point++;
    }
    if(led_path_left == 1 && led_path_front == 1 && led_path_right == 0 ){
    path = 'P';left();way[point] = 'L'; point++;
    }
    if(led_path_left == 1 && led_path_front == 1 && led_path_right == 1 ){    //check end left
    checkEndLeft();
    }
    LSRBalgo();
}
void RSLB(){
    if(led_path_left == 0 && led_path_front == 0 && led_path_right == 0 ){
    path = 'B';back();way[point] = 'B'; point++;
    }
    if(led_path_left == 0 && led_path_front == 0 && led_path_right == 1 ){
    path = 'R';right();way[point] = 'R'; point++;
    }
    if(led_path_left == 0 && led_path_front == 1 && led_path_right == 0 ){
    path = 'S';straight();way[point] = 'S'; point++;
    }
    if(led_path_left == 0 && led_path_front == 1 && led_path_right == 1 ){
    path = 'Q';right();way[point] = 'R'; point++;
    }
    if(led_path_left == 1 && led_path_front == 0 && led_path_right == 0 ){
    path = 'L';left();way[point] = 'L'; point++;
    }
    if(led_path_left == 1 && led_path_front == 0 && led_path_right == 1 ){
    path = 'T';right();way[point] = 'R'; point++;
    }
    if(led_path_left == 1 && led_path_front == 1 && led_path_right == 0 ){
    path = 'P';straight();way[point] = 'S'; point++;
    }
    if(led_path_left == 1 && led_path_front == 1 && led_path_right == 1 ){    //check end right
    checkEndRight();
    }
    RSLBalgo();
}

void LSRBalgo(){
  for(int i = 0; i <= point + 5; i++){

    if(way[i] == 'B'){

       if(way[i-1]=='L'&&way[i]=='B'&&way[i+1]=='R'){
          way[i-1] = 'B';point--;
       }
       if(way[i-1]=='L'&&way[i]=='B'&&way[i+1]=='S'){
          way[i-1] = 'R';point--;
       }
       if(way[i-1]=='R'&&way[i]=='B'&&way[i+1]=='L'){
          way[i-1] = 'B';point--;
       }
       if(way[i-1]=='S'&&way[i]=='B'&&way[i+1]=='L'){
          way[i-1] = 'R';point--;
       }
       if(way[i-1]=='S'&&way[i]=='B'&&way[i+1]=='S'){
          way[i-1] = 'B';point--;
       }
       if(way[i-1]=='L'&&way[i]=='B'&&way[i+1]=='L'){
          way[i-1] = 'S';point--;
       }
    }

  }
}

void RSLBalgo(){
  for(int i = 0; i <= point + 5; i++){

    if(way[i] == 'B'){

       if(way[i-1]=='R'&&way[i]=='B'&&way[i+1]=='L'){
          way[i-1] = 'B';point--;
       }
       if(way[i-1]=='R'&&way[i]=='B'&&way[i+1]=='S'){
          way[i-1] = 'L';point--;
       }
       if(way[i-1]=='L'&&way[i]=='B'&&way[i+1]=='R'){
          way[i-1] = 'B';point--;
       }
       if(way[i-1]=='S'&&way[i]=='B'&&way[i+1]=='R'){
          way[i-1] = 'L';point--;
       }
       if(way[i-1]=='S'&&way[i]=='B'&&way[i+1]=='S'){
          way[i-1] = 'B';point--;
       }
       if(way[i-1]=='R'&&way[i]=='B'&&way[i+1]=='R'){
          way[i-1] = 'S';point--;
       }
    }

  }
}