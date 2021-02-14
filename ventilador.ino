// O pino A0 terá um Sensor de Temperatura LM35 conectado.
int sensorTemperatura = A0;

int ventilador = 11;
int temperaturaLigarVentilador = 80;

// A rotina ‘setup’ será chamada assim que você ligar a placa na energia ou pressionar o botão ‘reset’.
void setup() {
	// Inicializamos o pino digital como uma entrada (input)
	pinMode(sensorTemperatura, INPUT);
	
	// Inicializados o pino digital do ventilador como saída (output)
	pinMode(ventilador, OUTPUT);

	// Inicializamos o Serial
	Serial.begin(9600);
}

float PegarGraus(int leitura) {
	// Pegamos o valor da leitura e aplicamos na fórmula para calcular a temperatura
	return (((5.0 * leitura) / 1024.0) - 0.5) * 100;
}

// A rotina ‘loop’ roda infinitamente na placa:
void loop() {
	// Gravamos o valor da leitura analógica do Sensor de Temperatura em uma variável
	int leituraSensorTemperatura = analogRead(sensorTemperatura);

	// Pegamos a leitura do sensor e transformamos em graus celsius
	float graus = PegarGraus(leituraSensorTemperatura);

	// Exibimos no Console o valor da temperatura, em graus celsius
	Serial.println(graus);
	
	if (graus > temperaturaLigarVentilador) {
		analogWrite(ventilador, 255);
	} else {
		digitalWrite(ventilador, LOW);
	}
}
