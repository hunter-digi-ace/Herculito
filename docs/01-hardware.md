[← Volver al índice](index.md)

# 01, Hardware y pinout

Componentes de Herculito según el esquemático
[`pcb_files/microsumo_pcb.pdf`](../pcb_files/microsumo_pcb.pdf).

## Componentes de la placa

| Ref. | Componente | Notas |
|---|---|---|
| `ARD1` | Arduino Mini (ATmega328P) | Cerebro del robot |
| `U1` | L293D | Driver de motores (doble puente H) |
| `D1` | LED azul | Estado (R1 = 330 Ω) |
| `D2` | LED verde | Estado (R2 = 330 Ω) |
| `D3` | LED amarillo | Estado (R3 = 330 Ω) |
| `D4` | LED rojo | Estado (R4 = 330 Ω) |
| `J1`, `J2` | Pads de motor | `M1` / `M2`, soldados directamente |
| `J3`–`J11` | Pads de 3 pines | Sensores (VCC / señal / GND) |
| `J13` | Pads de alimentación | `7.2V` |
| `SW1` | Interruptor | Encendido de la placa |

## Sensores

Los 6 sensores TCRT5000 van soldados directamente a la placa, cada uno con su
resistencia soldada en el aire. En el esquemático ocupan estos pads de 3 pines
del Arduino Mini:

| Pads placa | Pin Arduino |
|---|---|
| `J3` | `D6` |
| `J4` | `D7` |
| `J5` | `D8` |
| `J6` | `D9` |
| `J7` | `D10` |
| `J8` | `A0` |
| `J9` | `A1` |
| `J10` | `A2` |
| `J11` | `A3` |

Herculito usa 3 para el suelo y 3 para el enemigo (detalle en
[Sensores](03-sensores.md)).

## Alimentación

- Entrada `J13` a 7.2 V, con el interruptor `SW1` en placa.
- La entrada llega al `RAW` del Arduino Mini y al `VS` del L293D (etapa de
  potencia).
- `VSS` del L293D y la lógica del Arduino van a 5 V (regulador del propio
  Mini).

## Motores (`U1` L293D)

| Pin L293D | Función |
|---|---|
| `EN1` (1), `IN1` (2), `IN2` (7) | Motor 1 (`OUT1`=3, `OUT2`=6) → `M1` |
| `EN2` (9), `IN3` (10), `IN4` (15) | Motor 2 (`OUT3`=11, `OUT4`=14) → `M2` |
| `VS` (8) | Alimentación de motores |
| `VSS` (16) | Alimentación de lógica (5 V) |
| `GND` (4, 5, 12, 13) | Masa |

Los motores de los dos servos van soldados directamente al L293D (`M1` / `M2`).
A los servos se les quita el potenciómetro y la controladora: solo queda el
motor y la reductora, pegados en L para entrar en el tamaño del microsumo.

## LEDs de estado

Cuatro LEDs (azul, verde, amarillo y rojo) con sus resistencias de 330 Ω
(`R1`–`R4`), pensados para indicar el estado del robot.

---

[Siguiente: 02 - PCB →](02-pcb.md)