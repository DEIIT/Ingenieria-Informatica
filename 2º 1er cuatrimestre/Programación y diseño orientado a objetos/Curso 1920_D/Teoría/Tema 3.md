# TEMA 3

## §3.1 - HERENCIA

La herencia es un mecanismo que permite crear clases basándonos en otras, creando una relación que puede expresarse como *es un(a)*. Por ejemplo, si la clase `FrauLuna` hereda de `Opereta`, podemos afirmar que *Frau Luna* es, a todos los efectos e indubitablemente, una opereta. Esta relación es transitiva, ya que si `Opereta` hereda de `Musica`, `FrauLuna` podemos afirmar que *Frau Luna* es música.

Cuando una clase hereda de otra, decimos que un *descendiente* hereda de un *ancestro*, una *subclase* de una *superclase* o una *clase hija* de una *clase padre*. Una subclase hereda todo el código de su superclase, aunque esto no implica necesariamente que pueda acceder a sus elementos, dependiendo este acceso de la visibilidad de los mismos. Debido a esto, decimos que la herencia genera una relación de composición.

La herencia su utiliza para reutilizar el código de clases de forma más orgánica. Generalmente, las superclases son una generalización de las subclases, que a su vez son una especialización de sus superclases. Es muy importante tener en cuenta que, aunque se puede crear herencia con cualquier clase, sólo debe utilizarse si las subclases especializan, extienden o especifican las superclases y si éstas generalizan a las subclases. En cualquier otro caso, la herencia es absurda y trae consigo espaguetización del código.

La herencia puede ser **simple** si cada clase tiene únicamente una superclase y **múltiple** si tiene varios. La mayoría de lenguajes no permiten la herencia múltiple, pero sí la simple.

Una subclase puede redefinir los métodos de una superclase y sobreescribir sus atributos, que al fin y al cabo son suyos. En Ruby se puede acceder al código del método de la superclase que se está redefiniendo con la palabra reservada `super`, que se sustituye internamente a algo similar a `superclase.metodo_redefinido` y puede pasar argumentos de forma explícita o los que se le pasa al método que se está redefiniendo de forma implícita. En Java, `super` apunta a la superclase y debemos indicar el método al que queremos acceder tras él.

\pagebreak

**Ejemplo de herencia simple en Java:**

```java
class Edificio {
	private int fechaConstruccion;

	// ...

	Edificio () {
		fechaConstruccion = 1035;
	}

	int getFechaConstruccion () {
		return fechaConstruccion;
	}
}

class Zigurat extends Edificio {
	private String estado;

	// ...

	Zigurat () {
		estado = "alzándose esbelto bajo el firmamento";
	}

	String getEstado () {
		return estado;
	}
}

class Ruinas extends Zigurat {
	Ruinas () {
		estado = "Antiguamente" + super.getEstado()
		         + ", ahora yaciendo apacible en el olvido.";
	}

	// ...
}
```

\pagebreak

**Ejemplo de herencia simple en Ruby:**

```ruby
def Edificio
	def initialize
		@fecha_construccion = 1035
	end

	attr_reader :fecha_construccion

	# ...
end

def Zigurat < Edificio
	def initialize
		@estado = "alzándose esbelto bajo el firmamento"
	end

	attr_reader :estado

	# ...
end

def Ruinas < Zigurat
	def initialize
		@estado = "Antiguamente #{parent.estado} " \
		                      ", ahora yaciendo apacible en el olvido."
	end

	attr_reader :estado

	# ...
end
```

Es importante tener en cuenta que en Java no se pueden definir los métodos `final` y privados y que los métodos sobrecargados deben (aunque no es obligatorio) ir predecidos de `@Override`. Se puede cambiar la cabecera de los métodos sobrecargados tanto en su especificador de acceso (§3.2) y en el tipo devuelto, pudiendo devolver una subclase del mismo. En Ruby, la redefinición se produce al crear un método con el mismo nombre que en la superclase, pues no permite sobrecarga. En ambos lenguajes, todas las clases heredan implícitamente de `Object`.

En UML, las herencia se representa con una flecha que parte de la subclase y apunta a la superclase.

## §3.2 - ESPECIFICADORES DE ACCESO (VISIBILIDAD)

Los especificadores de acceso permiten **restringir el acceso** a los atributos y métodos por parte de clases externas. Por cuestiones de diseño, se busca restringir lo máximo posible el acceso de todos los atributos y métodos, impidiendo así que otras clases puedan modificar de forma indeseada los atributos o el comportamiento de la clase sin utilizar las interfaces diseñadas para ello.

Dependiendo del lenguaje, se pueden aplicar especificadores de acceso a otros elementos, como clases.

Existen tres especificadores de acceso válidos casi universalmente:

- **Público:** En general, visible en todo el código.
- **Privado:** En general, visible únicamente dentro de la clase.
- **Protegido:** En general, algo más restrictivo que *público*.

Existen variaciones. Java agrega la visibilidad de **paquete**, que restringe la publicidad del acceso a las clases del mismo paquete, mientras que Smalltalk sólo concibe el acceso público y protegido. También deben tenerse en cuenta las posibles variaciones del significado de los espeficicadores en función del lenguaje.

### §3.2.1 - Java

En Java, cada elemento debe incluir su propio especificador de acceso.

```java
	private int metodo1 (arg1, arg2) {
		// ...
	}

	public String metodo2 () {
		// ...
	}
```

El especificador `private` da acceso a los métodos y atributos desde el código de la propia clase, pudiendo acceder una instancia a los datos privados de otra de la misma clase, por ejemplo, si se pasa como parámetro de un método.

El espeficiador de paquete, que no se explicita, permite visibilidad pública ante todos los métodos del mismo paquete y privada ante los externos al mismo.

El especificador `protected` permite visibilidad desde diferentes instancias de la misma clase y desde las subclases de la misma. Sin embargo, una instancia no puede acceder a los métodos protegidos de una instancia de una clase de la cual hereda pero no es su superclase. Por ejemplo, `Coloso miColoso`, que hereda de `Maravilla miMaravilla`, puede acceder a los elementos protegidos de `miMaravilla`, pero no a los de `Maravilla otraMaravilla`, a menos que éste sea una superclase de `Coloso otroColoso`. Sin embargo, es importante tener en cuenta que los elementos protegidos son públicos dentro de su mismo paquete.

El especificador `public` permite utilizar los métodos y atributos desde cualquier método del programa.

### §3.2.2 - Ruby

En Ruby, los atributos son siempre privados y los métodos, públicos. Como excepción, `initialize` siempre es privado y no se puede cambiar. La declaración de un especificador de acceso afecta a todos los métodos siguientes hasta que se utilice otro.

```ruby
private

	# Tanto metodo1 como metodo2 son privados

	def metodo1 arg1, arg2
		# ...
	end

	def metodo2 arg1, arg2, arg3
		# ...
	end
```

El especificador `private` impide que se puedan llamar los métodos mediante receptores explícitos, impidiendo también usar `self` para llamarlo. Por tanto, sólo pueden usarse desde la propia instancia. Igualmente, si una instancia `B` hereda de `A`, se puede accedor a los métodos privados de `B` desde `A ` y vicecersa. Sin embargo, no se puede acceder a métodos privados de clase desde el ámbito de la instancia y viceversa.

El especificador `protected` sí permite que los métodos a los que se refiere puedan ser invocado con un receptor explícito, pudiendo invocarse desde instancias de la misma clase o desde una subclase. No existen los métodos protegidos de clase.

Es importante recordar que en Ruby una clase y sus instancias no son de la misma clase, ya que la clase es un objeto en sí misma. Igualmente, los atributos de clase también son accesibles directamente desde el ámbito de instancia.

## §3.3 - CLASES ABSTRACTAS

Existe la posibilidad de que varias clases que heredan de una superclase contengan un método común con implementaciones distintas. Por ejemplo, el método `float velocidadGalope ()` de la clase `Caballo` no devolverá lo mismo en la clase `CaballoDelBueno` y `CaballoDelMalo`, aunque ambas hereden de `Caballo`.

Para esto existe la solución de las **clases abstractas**, que incorporan prototipos de métodos sin su implementación para que sus diferentes subclases lo implementen como les sea conveniente.

```java
abstract class Caballo {
// ...
	abstract float velocidadGalope (); // Método abstracto
}

class CaballoDelBueno extends Caballo {
// ...
	float velocidadGalope () {
		// Galopa muy rápido
	}
}

class CaballoDelMalo extends Caballo {
// ...
	float velocidadGalope () {
		// Galopa lentillo
	}
}
```

Si una clase contiene un prototipo sin implementación debe ser obligatoriamente denominada como `abstract`. Estas clases no se puedeninstanciar, pero sí se puede declarar una variable usándola como tipo. Su función principal es de diseño, ya que obligan a sus subclases a implementar todos sus métodos para poder ser utilizadas y definen un tipo de dato común para todas ellas.

Ruby no da soporte a clases abstractas y no incorpora ningún mecanismo de comprobación por adelantado para el buen uso de variable. Lo más cercano que se puede hacer es crear una superclase no instanciable y crear clases instanciables a partir de ella.

```ruby
class Superclase
	# ...
	private_class_method :new
end

class Clase < Superclase
	public_class_method :new
	# ...
end
```

En UML, las clases abstractas se representan mediante `<<abstract>>` o **escribiendo el nombre en cursiva**.

## §3.4 - INTERFACES

Las **interfaces** son elementos no instanciables por sí mismos que definen un protocolo de comportamiento para las clases que las implmentan.

En Java, una clase puede implementar varias interfaces y a su ves éstas pueden hereder de tantas otras como quieran. Las interfaces sólo pueden tener constantes, prototipos y métodos `default` y `static`, sólo pudienod implementarse estos dos últimos. Todos los métodos son `public` y las constantes `public`, `static` y `final`.

Una clase que hereda un método `default` de una interfaz puede redefinirlo y debe hacerlo si hereda varios métodos `default` con el mismo prototipo de varias interfaces diferentes. Las clases abstractas pueden implementar interfaces sin implementar sus métodos.

```java
interface Interfaz1 {
	int Constante1 = 33;

	int implementame ();
	default String muestraNumero () {
		return "Número 1";
	}
}

interface Interfaz2 {
	String saludo () {
		return "Hola holita, vecinito.";
	}

	default String muestraNumero () {
		return "Ésta es la interfaz nº 2";
	}
}


class Clase implements Interfaz1, Interfaz2 {
	@Override
	public String implementame () {
		return "¡Implementada!";
	}

	@Override
	public String muestraNumero () {
		return "La interfaz 1 no dice nada pero la 2 dice:\n"
		       + Interfaz2.super.saludo();
	}
}
```
