#include <Servo.h>  //아두이노 서보모터 제어 라이브러리
 
Servo test_motor; // test_motor 라는 이름을 지정합니다.

int val=93; //모터의 속도를 책임질 변수를 선언합니다.
 
void setup() {
  Serial.begin(9600); //플로팅 시리얼을 통하여 속도를 제어하기 위하여 통신 속도를 지정합니다.
  test_motor.attach(6); //PWM신호를 출력할 핀을 9번으로 설정합니다.      
  test_motor.write(60); //아두이노가 동작을 시작하면 초기 속도로 60을 지정하고 3초를 대기합니다.
  delay(3000);                        
}
 
void loop() {
  if(Serial.available()){
    char temp = Serial.read();
    if(temp=='u'){    //u를 입력하여 속도를 올리고
      val += 1;
    }
    else if(temp=='d'){ //d를 입력하여 속도를 낮춥니다.
      val -= 1;
    }
    test_motor.write(val);  //루프를 반복하여 실시간으로 속도를 제어합니다.
  }
  Serial.print("current value : ");
  Serial.println(val); 
  delay(100);
}
