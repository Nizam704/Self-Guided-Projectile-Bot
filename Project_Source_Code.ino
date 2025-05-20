1	#include <Servo.h>         //servo motor library
2	const int servo1Pin = 12;  //servo motor 1 pin no
3	const int servo2Pin = 13;  //servo motor 2 pin no
4	
5	//make servo class
6	Servo servo1;
7	Servo servo2;
8	
9	//define ultrasonic 1 pins
10	#define trig1Pin A3
11	#define echo1Pin A4
12	
13	//define ultrasonic 1 pins
14	#define trig2Pin A5
15	#define echo2Pin A8
16	
17	//define ultrasonic1 parameter
18	long duration1;
19	int distance1;
20	
21	//define ultrasonic2 parameter
22	long duration2;
23	int distance2;
24	
25	int ENA = 7;  //enable pin for motor A
26	int ENB = 2;  //enable pin for motor B
27	int IN1 = 6;  //control pin 1 for motor A
28	int IN2 = 5;  //control pin 2 for motor A
29	int IN3 = 4;  //control pin 1 for motor B
30	int IN4 = 3;  //control pin 2 for motor B
31	
32	 int L = A1;
33	 int C = A2;
34	 int R = A3;
35	
36	 int junction = 0;
37	 int sensorL;
38	 int sensorC;
39	 int sensorR;
40	 void setup() {
41	  // put your setup code here, to run once:
42	  pinMode(trig1Pin, OUTPUT);  // Sets the trigPin as an Output
43	  pinMode(echo1Pin, INPUT);   // Sets the echoPin as an Input
44	  //ultrasonic 2
45	  pinMode(trig2Pin, OUTPUT);  // Sets the trigPin as an Output
46	  pinMode(echo2Pin, INPUT);   // Sets the echoPin as an Input
47	  //servo 1
48	  servo1.attach(servo1Pin);
49	  //servo 2
50	  servo2.attach(servo2Pin);
51	  pinMode(ENA, OUTPUT);
52	  pinMode(ENB, OUTPUT);
53	  pinMode(IN1, OUTPUT);
54	  pinMode(IN2, OUTPUT);
55	  pinMode(IN3, OUTPUT);
56	  pinMode(IN4, OUTPUT);
57	
58	  pinMode(L, INPUT);
59	  pinMode(C, INPUT);
60	  pinMode(R, INPUT);
61	}
62	
63	 void forward() {
64	  analogWrite(ENA, 255);
65	  analogWrite(ENB, 255);
66	  digitalWrite(IN1, HIGH);
67	  digitalWrite(IN2, LOW);
68	  digitalWrite(IN3, HIGH);
69	  digitalWrite(IN4, LOW);
70	}
71	
72	void left() {
73	  analogWrite(ENA, 255);  //you can adjust the speed of the motors from 0-255
74	  analogWrite(ENB, 255);  //you can adjust the speed of the motors from 0-255
75	  digitalWrite(IN1, LOW);
76	  digitalWrite(IN2, HIGH);
77	  digitalWrite(IN3, HIGH);
78	  digitalWrite(IN4, LOW);
79	}
80	
81	void right() {
82	  analogWrite(ENA, 255);  //you can adjust the speed of the motors from 0-255
83	  analogWrite(ENB, 255);  //you can adjust the speed of the motors from 0-255
84	  digitalWrite(IN1, HIGH);
85	  digitalWrite(IN2, LOW);
86	  digitalWrite(IN3, LOW);
87	  digitalWrite(IN4, HIGH);
88	}
89	
90	void stop() {
91	  analogWrite(ENA, 0);
92	  analogWrite(ENB, 0);
93	  digitalWrite(IN1, LOW);
94	  digitalWrite(IN2, LOW);
95	  digitalWrite(IN3, LOW);
96	  digitalWrite(IN4, LOW);
97	}
98	
99	void follow() {
100	  if (sensorL == 0 && sensorC == 1 && sensorR == 0) {
101	    forward();
102	  }
103	
104	  else if (sensorL == 1 && sensorC == 0 && sensorR == 0) {
105	    left();
106	  }
107	
108	  else if (sensorL == 1 && sensorC == 1 && sensorR == 0) {
109	    left();
110	  }
111	
112	  else if (sensorL == 0 && sensorC == 0 && sensorR == 1) {
113	    right();
114	  }
115	
116	  else if (sensorL == 0 && sensorC == 1 && sensorR == 1) {
117	    right();
118	  }
119	}
120	
121	void IR() {
122	  // put your main code here, to run repeatedly:
123	
124	  sensorL = digitalRead(L);
125	  sensorC = digitalRead(C);
126	  sensorR = digitalRead(R);
127	}
128	
129	void loop() {
130	  // put your main code here, to run repeatedly:
131	  IR();
132	  if (sensorL == 0 && sensorC == 1 && sensorR == 0) {
133	    forward();
134	  }
135	
136	  else if (sensorL == 1 && sensorC == 0 && sensorR == 0) {
137	    left();
138	  }
139	
140	  else if (sensorL == 1 && sensorC == 1 && sensorR == 0) {
141	    left();
142	  }
143	
144	  else if (sensorL == 0 && sensorC == 0 && sensorR == 1) {
145	    right();
146	  }
147	
148	  else if (sensorL == 0 && sensorC == 1 && sensorR == 1) {
149	    right();
150	  } else if (sensorL == 1 && sensorC == 1 && sensorR == 1) {
151	    forward();
152	    junction++;
153	
154	    if ((junction == 1)) {
155	      right();
156	      delay(800);
157	
158	    } else if (junction == 2) {
159	      forward();
160	      delay(400);
161	      follow();
162	    }
163	
164	    else if (junction == 3) {
165	      left();
166	      delay(800);
167	    }
168	
169	    else if (junction == 4) {
170	      stop();
171	      delay(500);
172	      shoot();  //shoot
173	      delay(1000);
174	      left();
175	      delay(800);
176	    } else if (junction == 5) {
177	      stop();
178	      delay(500);
179	      shoot();  //shoot
180	      delay(1000);
181	      right();
182	      delay(800);
183	    } else if (junction == 6) {
184	      left();
185	      delay(800);
186	    } else if (junction == 7) {
187	      forward();
188	      delay(800);
189	    } else if (junction == 8) {
190	      stop();
191	      delay(2000);
192	      right();
193	      delay(800);
194	      delay(500);
195	      shoot();  //shoot
196	      delay(1000);
197	      left();  //uturn
198	      delay(800);
199	      forward();
200	      delay(800);
201	    } else if (junction == 9) {
202	      right();
203	      delay(800);
204	      stop();  //shoot
205	      delay(500);
206	      shoot();  //shoot
207	      delay(1000);
208	      left();
209	      delay(800);
210	      stop();  //shoot
211	      delay(500);
212	      shoot();  //shoot
213	      delay(1000);
214	      left();
215	      delay(800);
216	      stop();
217	      delay(10000);  
218	    }
219	  }
220	}
221	void shoot() {
222	
223	  // Clears the trigPin
224	  digitalWrite(trig1Pin, LOW);
225	  delayMicroseconds(2);
226	  // Sets the trigPin on HIGH state for 10 micro seconds
227	  digitalWrite(trig1Pin, HIGH);
228	  delayMicroseconds(10);
229	  digitalWrite(trig1Pin, LOW);
230	  // Reads the echoPin, returns the sound wave travel time in microseconds
231	  duration1 = pulseIn(echo1Pin, HIGH);
232	  // Calculating the distance
233	  distance1 = duration1 * 0.034 / 2;
234	  // Prints the distance on the Serial Monitor
235	  Serial.print("Distance1: ");
236	  Serial.println(distance1);
237	
238	  // Clears the trigPin
239	  digitalWrite(trig2Pin, LOW);
240	  delayMicroseconds(2);
241	  // Sets the trigPin on HIGH state for 10 micro seconds
242	  digitalWrite(trig2Pin, HIGH);
243	  delayMicroseconds(10);
244	  digitalWrite(trig2Pin, LOW);
245	  // Reads the echoPin, returns the sound wave travel time in microseconds
246	  duration2 = pulseIn(echo2Pin, HIGH);
247	  //Calculating the distance
248	  distance2 = duration2 * 0.034 / 2;
249	  // Prints the distance on the Serial Monitor
250	  Serial.print("Distance2: ");
251	  Serial.println(distance2);
252	
253	  if ((distance1 < 50 && distance1 > 0) && (distance2 > 60)) {
254	    delay(1000);
255	    servo1.write(60);
256	    delay(200);
257	    servo1.write(0);
258	    delay(1000);
259	  }
260	
261	  if (((distance2 < 50 && distance2 > 0) && (distance1 < 50 && distance1 > 0)) || ((distance2 < 50 && distance2 > 0) && (distance1 > 60))) {
262	    delay(1000);
263	    servo2.write(30);
264	    delay(150);
265	    servo2.write(0);
266	    delay(1000);
267	  }
268	}
