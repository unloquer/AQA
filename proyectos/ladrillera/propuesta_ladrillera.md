<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#org65710cd">1. Agentes Calidad del Aire</a>
<ul>
<li><a href="#org17b0934">1.1. Justificación</a></li>
<li><a href="#org3b60fa9">1.2. Problema</a></li>
<li><a href="#orge3aaf79">1.3. Solución propuesta</a></li>
<li><a href="#org36285a7">1.4. Fases</a>
<ul>
<li><a href="#org2e8d253">1.4.1. Primer fase:</a></li>
<li><a href="#orgff6c4fa">1.4.2. Segunda Fase:</a></li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
</div>

<a id="org65710cd"></a>

# Agentes Calidad del Aire


<a id="org17b0934"></a>

## Justificación

El Valle de Aburrá sufre un problema de acción colectiva en cuanto a la calidad del aire, pues, además de una topografía poco favorable para dispersar los gases contaminantes que la ciudad emite cada día, no existe un mecanismo que permita evidenciar el costo de las externalidades negativas por emisión de gases, así como los responsables directos de las mismas. Esto origina debilidad en el entendimiento del problema mismo, las políticas públicas no son capaces de hacer frente a la situación y se produce de forma generalizada la situación de "free-riders". La realidad es que no todos contaminamos igual, pero todos sí sufrimos las consecuencias de un aire en mal estado. 

Los efectos en la salud pública son la muestra más visible y urgente del problema. Estudios del Departamento Nacional de Planeación (DNP) revelan que la contaminación del aire urbano aporta el 75% de los gastos al sistema de salud colombiano por muertes y enfermedades asociadas a la degradación ambiental en Colombia, es decir, cerca de 15,4 billones de pesos. Esto significa 10 mil 527 personas entre 2015 y 2016 por esta causa. La ciudad con mayor número de casos es Medellín, con 2.105, que representan el 12,3 por ciento del total de las muertes que se presentan en esa ciudad. Esto representa un costo para la capital antioqueña de 2,8 billones de pesos, equivalentes al 5 por ciento del PIB de su Área Metropolitana. 

Las mediciones del Área Metropolitana del Valle de Aburrá muestran que 79% de las emisiones de PM 2.5, la partícula de contaminación más dañina para el ser humana, provienen de las fuentes móviles. Si bien se conoce que la solución de más impacto es la renovación del parque automotor más contaminante, el problema político inherente está en quién debe asumir el costo de esa renovación. Un primer paso está en el reconocimiento del problema, como ya hoy lo permite el Siata, pero este sistema de monitoreo es limitado pues no permite conocer el detalles claves del problema como los lugares precisos que presentan más contaminación, la calidad del aire que efectivamente están respirando las personas y los responsables directos. 

A raíz de esta situación, en marzo de 2017 el colectivo Datos y Gobierno Abierto Medellín realizó una jornada de trabajo durante el 'Open Data Day Medellin' (goo.gl/wacA5X), en la que se priorizaron los siguientes puntos como espacios de oportunidad para la generación de soluciones a la contaminación del aire:
1. La falta de información pública en términos de datos abiertos respecto a la calidad del aire y sus problemáticas conexas. Esto repercute en la dificultad para reconocer el problema y sus evidencias, además de hacer menos transparente el proceso de gestión de calidad del aire.
2. La falta de iniciativas pedagógicas dirigidas a la ciudadanía para que pueda aprender, comprender y proponer frente a la problemática actual del aire.
3. La falta de sensores y dispositivos ciudadanos de bajo costo que contribuyan a la captura, procesamiento y análisis de información sobre la calidad del aire.

<a id="org3b60fa9"></a>

## Problema

Con base en lo anterior, esta propuesta apunta a la generación de una solución para el ciudadano que no tiene una medición del aire que respira en el momento, así como la falta de datos de detalle sobre la calidad de aire que efectivamente respiran los habitantes de la ciudad. 

<a id="orge3aaf79"></a>

## Solución propuesta

Medidor portable que indique visualmente la calidad del aire y que permita agregar esas mediciones en una plataforma pública en línea con funcionalidades para el análisis de datos.


<a id="org36285a7"></a>

## Fases


<a id="org2e8d253"></a>

### Primer fase:

1.  Puntos fijos

2.  con plataforma web de captura de datos,

3.  alimentación de energía

4.  transmisión vía WiFi

5.  (Opción almacenaje de datos en SD?)

6.  Uso de los datos:

    1.  a. Publicación de dataset (Open Data), sin procesamiento o con depuración??
    
    2.  b. Publicación básica de resultados en web responsive, en mapas y capas de análisis básico.

7.  Presupuesto fase 1:

    <table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">
    
    
    <colgroup>
    <col  class="org-left" />
    
    <col  class="org-left" />
    
    <col  class="org-left" />
    
    <col  class="org-left" />
    
    <col  class="org-left" />
    
    <col  class="org-left" />
    </colgroup>
    <tbody>
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">&#xa0;</td>
    </tr>
    
    
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">Date</td>
    <td class="org-left">Payee</td>
    <td class="org-left">Account</td>
    <td class="org-left">Amount</td>
    <td class="org-left">Balance</td>
    </tr>
    
    
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">01-Jan-01</td>
    <td class="org-left">Sensor de partículas</td>
    <td class="org-left">fase1:costo:aparato:componente:sensor</td>
    <td class="org-left">$ -20.00</td>
    <td class="org-left">$ -20.00</td>
    </tr>
    
    
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">01-Jan-01</td>
    <td class="org-left">ESP8266</td>
    <td class="org-left">fase1:costo:aparato:componente:esp</td>
    <td class="org-left">$ -10.00</td>
    <td class="org-left">$ -30.00</td>
    </tr>
    
    
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">01-Jan-01</td>
    <td class="org-left">DHT (sensor de humedad y temperatura)</td>
    <td class="org-left">fase1:costo:aparato:componente:sensor:dht</td>
    <td class="org-left">$ -0.65</td>
    <td class="org-left">$ -30.65</td>
    </tr>
    
    
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">01-Jan-01</td>
    <td class="org-left">Leds</td>
    <td class="org-left">fase1:costo:aparato:componente:feedback:led</td>
    <td class="org-left">$ -0.16</td>
    <td class="org-left">$ -30.81</td>
    </tr>
    
    
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">01-Jan-01</td>
    <td class="org-left">Alimentación Energía</td>
    <td class="org-left">fase1:costo:aparato:componente:energia:adaptador</td>
    <td class="org-left">$ -6.00</td>
    <td class="org-left">$ -36.81</td>
    </tr>
    
    
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">01-Jan-01</td>
    <td class="org-left">Ensamblaje</td>
    <td class="org-left">fase1:costo:aparato:manoDeObra:ensamblaje</td>
    <td class="org-left">$ -17.00</td>
    <td class="org-left">$ -53.81</td>
    </tr>
    
    
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">01-Jan-01</td>
    <td class="org-left">Diseño electrónico</td>
    <td class="org-left">fase1:costo:aparato:manoDeObra:diseno</td>
    <td class="org-left">$ -17.00</td>
    <td class="org-left">$ -70.81</td>
    </tr>
    
    
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">01-Jan-01</td>
    <td class="org-left">Cableado</td>
    <td class="org-left">fase1:costo:aparato:manoDeObra:cableado</td>
    <td class="org-left">$ -1.00</td>
    <td class="org-left">$ -71.81</td>
    </tr>
    
    
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">01-Jan-01</td>
    <td class="org-left">Carcasa</td>
    <td class="org-left">fase1:costo:aparato:manoDeObra:diseno:carcasa</td>
    <td class="org-left">$ -20.00</td>
    <td class="org-left">$ -91.81</td>
    </tr>
    
    
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">01-Jan-01</td>
    <td class="org-left">Código</td>
    <td class="org-left">fase1:costo:aparato:manoDeObra:codigo</td>
    <td class="org-left">$ -10.00</td>
    <td class="org-left">$ -101.81</td>
    </tr>
    
    
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">01-Jan-01</td>
    <td class="org-left">Infraestructura</td>
    <td class="org-left">fase1:costo:aparato:infraestructura</td>
    <td class="org-left">$ -12.00</td>
    <td class="org-left">$ -113.81</td>
    </tr>
    
    
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">01-Jan-01</td>
    <td class="org-left">Impuestos IVA 19%</td>
    <td class="org-left">fase1:costo:aparato:impuestos</td>
    <td class="org-left">$ -21.47</td>
    <td class="org-left">$ -135.28</td>
    </tr>
    
    
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">01-Jan-01</td>
    <td class="org-left">Utilidad</td>
    <td class="org-left">fase1:costo:aparato:utilidad</td>
    <td class="org-left">$ -22.60</td>
    <td class="org-left">$ -157.88</td>
    </tr>
    </tbody>
    </table>


<a id="orgff6c4fa"></a>

### Segunda Fase:

1.  Puntos móviles con gps (Batería,

2.  transmisión vía WiFi o SimCard?,

3.  (opción de almacenar en SD).

4.  Uso de los datos:

    1.  a. Publicación de dataset (Open Data), sin procesamiento o con depuración??
    
    2.  b. Publicación básica de resultados en web responsive, en mapas y capas de análisis básico.
    
    3.  c. Desarrollo de aplicación móvil (Android, posiblemente ios).

