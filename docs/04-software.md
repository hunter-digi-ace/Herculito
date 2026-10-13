[← Volver al índice](index.md)

# 04, Software

## Siguelineas

Sketch para seguir la línea con los tres sensores de suelo:
[`source_code/siguelineas/HerculitoSiguelineas.ino`](../source_code/siguelineas/HerculitoSiguelineas.ino).

- Motores (L293D): `motorA1` = `D2`, `motorA2` = `D3`, `motorB1` = `D4`,
  `motorB2` = `D5`.
- Sensores: `left` = `D7`, `right` = `D6`, `back` = `D8`.
- `turn_delay` = 50 ms.

Con la lectura de los tres sensores decide entre `izquierda()`, `derecha()`,
`adelante()` o `parar()`.

---

[← 03 - Sensores](03-sensores.md)  |  [Volver al índice ↑](index.md)