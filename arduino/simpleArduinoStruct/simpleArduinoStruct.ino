const int maxMember = 3;
struct member {
  String id;
  String user;
  long balance;
};

member card[maxMember];
void setup() {
  card[0].id = "7K IO P9 88";
  card[0].user = "WAHYU";
  card[0].balance = 250000;

  card[1].id = "P9 UY 87 GG";
  card[1].user = "JOHN";
  card[1].balance = 500000;

  card[1].id = "7K 76 YY TT";
  card[1].user = "NAJWA";
  card[1].balance = 500;
  
  Serial.begin(115200);
}

void loop() {
  for (int i = 0; i < maxMember; i++) {
    Serial.print("ID    :"); Serial.println(card[i].id);
    Serial.print("NAME  :"); Serial.println(card[i].user);
    Serial.print("SALDO :"); Serial.println(card[i].balance);
  }

}
