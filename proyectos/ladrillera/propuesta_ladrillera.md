<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#org6e1e0bf">1. Agentes Calidad del Aire</a>
<ul>
<li><a href="#org526cd84">1.1. Justificación</a></li>
<li><a href="#orge21955c">1.2. Problema</a></li>
<li><a href="#orgf99aaa4">1.3. Solución propuesta</a></li>
<li><a href="#org3859f35">1.4. Fases</a>
<ul>
<li><a href="#orgd3f207a">1.4.1. Primer fase:</a></li>
<li><a href="#org5c07fcc">1.4.2. Segunda Fase:</a></li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
</div>

<a id="org6e1e0bf"></a>

# Agentes Calidad del Aire


<a id="org526cd84"></a>

## Justificación

El Valle de Aburrá sufre un problema de acción colectiva en cuanto a la calidad del aire, pues, además de una topografía poco favorable para dispersar los gases contaminantes que la ciudad emite cada día, no existe un mecanismo que permita evidenciar el costo de las externalidades negativas por emisión de gases, así como los responsables directos de las mismas. Esto origina debilidad en el entendimiento del problema mismo, las políticas públicas no son capaces de hacer frente a la situación y se produce de forma generalizada la situación de "free-riders". La realidad es que no todos contaminamos igual, pero todos sí sufrimos las consecuencias de un aire en mal estado. 

Los efectos en la salud pública son la muestra más visible y urgente del problema. Estudios del Departamento Nacional de Planeación (DNP) revelan que la contaminación del aire urbano aporta el 75% de los gastos al sistema de salud colombiano por muertes y enfermedades asociadas a la degradación ambiental en Colombia, es decir, cerca de 15,4 billones de pesos. Esto significa 10 mil 527 personas entre 2015 y 2016 por esta causa. La ciudad con mayor número de casos es Medellín, con 2.105, que representan el 12,3 por ciento del total de las muertes que se presentan en esa ciudad. Esto representa un costo para la capital antioqueña de 2,8 billones de pesos, equivalentes al 5 por ciento del PIB de su Área Metropolitana. 

Las mediciones del Área Metropolitana del Valle de Aburrá muestran que 79% de las emisiones de PM 2.5, la partícula de contaminación más dañina para el ser humana, provienen de las fuentes móviles. Si bien se conoce que la solución de más impacto es la renovación del parque automotor más contaminante, el problema político inherente está en quién debe asumir el costo de esa renovación. Un primer paso está en el reconocimiento del problema, como ya hoy lo permite el Siata, pero este sistema de monitoreo es limitado pues no permite conocer el detalles claves del problema como los lugares precisos que presentan más contaminación, la calidad del aire que efectivamente están respirando las personas y los responsables directos. 

A raíz de esta situación, en marzo de 2017 el colectivo Datos y Gobierno Abierto Medellín realizó una jornada de trabajo durante el 'Open Data Day Medellin' (goo.gl/wacA5X), en la que se priorizaron los siguientes puntos como espacios de oportunidad para la generación de soluciones a la contaminación del aire:
1. La falta de información pública en términos de datos abiertos respecto a la calidad del aire y sus problemáticas conexas. Esto repercute en la dificultad para reconocer el problema y sus evidencias, además de hacer menos transparente el proceso de gestión de calidad del aire.
2. La falta de iniciativas pedagógicas dirigidas a la ciudadanía para que pueda aprender, comprender y proponer frente a la problemática actual del aire.
3. La falta de sensores y dispositivos ciudadanos de bajo costo que contribuyan a la captura, procesamiento y análisis de información sobre la calidad del aire.

<a id="orge21955c"></a>

## Problema

Con base en lo anterior, esta propuesta apunta a la generación de una solución para el ciudadano que no tiene una medición del aire que respira en el momento, así como la falta de datos de detalle sobre la calidad de aire que efectivamente respiran los habitantes de la ciudad. 

<a id="orgf99aaa4"></a>

## Solución propuesta

Medidor portable que indique visualmente la calidad del aire y que permita agregar esas mediciones en una plataforma pública en línea con funcionalidades para el análisis de datos.


<a id="org3859f35"></a>

## Fases


<a id="orgd3f207a"></a>

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
    </colgroup>
    <thead>
    <tr>
    <th scope="col" class="org-left">Payee</th>
    <th scope="col" class="org-left">Account</th>
    <th scope="col" class="org-left">Amount</th>
    <th scope="col" class="org-left">Balance</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Sensor de partículas</th>
    <th scope="col" class="org-left">fase1:costo:aparato:componente:sensor</th>
    <th scope="col" class="org-left">$ -20.00</th>
    <th scope="col" class="org-left">$ -20.00</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">ESP8266</th>
    <th scope="col" class="org-left">fase1:costo:aparato:componente:esp</th>
    <th scope="col" class="org-left">$ -10.00</th>
    <th scope="col" class="org-left">$ -30.00</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">DHT (sensor de humedad y temperatura)</th>
    <th scope="col" class="org-left">fase1:costo:aparato:componente:sensor:dht</th>
    <th scope="col" class="org-left">$ -0.65</th>
    <th scope="col" class="org-left">$ -30.65</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Leds</th>
    <th scope="col" class="org-left">fase1:costo:aparato:componente:feedback:led</th>
    <th scope="col" class="org-left">$ -0.16</th>
    <th scope="col" class="org-left">$ -30.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Alimentación Energía</th>
    <th scope="col" class="org-left">fase1:costo:aparato:componente:energia:adaptador</th>
    <th scope="col" class="org-left">$ -6.00</th>
    <th scope="col" class="org-left">$ -36.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Ensamblaje</th>
    <th scope="col" class="org-left">fase1:costo:aparato:manoDeObra:ensamblaje</th>
    <th scope="col" class="org-left">$ -17.00</th>
    <th scope="col" class="org-left">$ -53.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Diseño electrónico</th>
    <th scope="col" class="org-left">fase1:costo:aparato:manoDeObra:diseno</th>
    <th scope="col" class="org-left">$ -17.00</th>
    <th scope="col" class="org-left">$ -70.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Cableado</th>
    <th scope="col" class="org-left">fase1:costo:aparato:manoDeObra:cableado</th>
    <th scope="col" class="org-left">$ -1.00</th>
    <th scope="col" class="org-left">$ -71.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Carcasa</th>
    <th scope="col" class="org-left">fase1:costo:aparato:manoDeObra:diseno:carcasa</th>
    <th scope="col" class="org-left">$ -20.00</th>
    <th scope="col" class="org-left">$ -91.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Código</th>
    <th scope="col" class="org-left">fase1:costo:aparato:manoDeObra:codigo</th>
    <th scope="col" class="org-left">$ -10.00</th>
    <th scope="col" class="org-left">$ -101.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Infraestructura</th>
    <th scope="col" class="org-left">fase1:costo:aparato:infraestructura</th>
    <th scope="col" class="org-left">$ -12.00</th>
    <th scope="col" class="org-left">$ -113.81</th>
    </tr>
    </thead>
    
    <tbody>
    <tr>
    <td class="org-left">Impuestos IVA 19%</td>
    <td class="org-left">fase1:costo:aparato:impuestos</td>
    <td class="org-left">$ -21.47</td>
    <td class="org-left">$ -135.28</td>
    </tr>
    
    
    <tr>
    <td class="org-left">Utilidad</td>
    <td class="org-left">fase1:costo:aparato:utilidad</td>
    <td class="org-left">$ -22.60</td>
    <td class="org-left">$ -157.88</td>
    </tr>
    </tbody>
    
    <tbody>
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">Total</td>
    <td class="org-left">$ -157.88</td>
    </tr>
    </tbody>
    </table>


<a id="org5c07fcc"></a>

### Segunda Fase:

1.  Puntos móviles con gps (Batería,

2.  transmisión vía WiFi o SimCard?,

3.  (opción de almacenar en SD).

4.  Uso de los datos:

    1.  a. Publicación de dataset (Open Data), sin procesamiento o con depuración??
    
    2.  b. Publicación básica de resultados en web responsive, en mapas y capas de análisis básico.
    
    3.  c. Desarrollo de aplicación móvil (Android, posiblemente ios).

5.  Presupuesto fase 2:

    <table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">
    
    
    <colgroup>
    <col  class="org-left" />
    
    <col  class="org-left" />
    
    <col  class="org-left" />
    
    <col  class="org-left" />
    </colgroup>
    <thead>
    <tr>
    <th scope="col" class="org-left">Payee</th>
    <th scope="col" class="org-left">Account</th>
    <th scope="col" class="org-left">Amount</th>
    <th scope="col" class="org-left">Balance</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">ESP8266</th>
    <th scope="col" class="org-left">fase2:costo:aparato:componente:esp</th>
    <th scope="col" class="org-left">$ -10.00</th>
    <th scope="col" class="org-left">$ -10.00</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Sensor de partículas</th>
    <th scope="col" class="org-left">fase2:costo:aparato:componente:sensor</th>
    <th scope="col" class="org-left">$ -20.00</th>
    <th scope="col" class="org-left">$ -30.00</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Gps</th>
    <th scope="col" class="org-left">fase2:costo:aparato:componente:gps</th>
    <th scope="col" class="org-left">$ -12.00</th>
    <th scope="col" class="org-left">$ -42.00</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">DHT (sensor de humedad y temperatura)</th>
    <th scope="col" class="org-left">fase2:costo:aparato:componente:sensor:dht</th>
    <th scope="col" class="org-left">$ -0.65</th>
    <th scope="col" class="org-left">$ -42.65</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Leds</th>
    <th scope="col" class="org-left">fase2:costo:aparato:componente:feedback:led</th>
    <th scope="col" class="org-left">$ -0.16</th>
    <th scope="col" class="org-left">$ -42.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Alimentación Energía</th>
    <th scope="col" class="org-left">fase2:costo:aparato:componente:energia:adaptador</th>
    <th scope="col" class="org-left">$ -6.00</th>
    <th scope="col" class="org-left">$ -48.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Batería</th>
    <th scope="col" class="org-left">fase2:costo:aparato:componente:energia:bateria</th>
    <th scope="col" class="org-left">$ -6.00</th>
    <th scope="col" class="org-left">$ -54.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Ensamblaje</th>
    <th scope="col" class="org-left">fase2:costo:aparato:manoDeObra:ensamblaje</th>
    <th scope="col" class="org-left">$ -17.00</th>
    <th scope="col" class="org-left">$ -71.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Diseño electrónico</th>
    <th scope="col" class="org-left">fase2:costo:aparato:manoDeObra:diseno</th>
    <th scope="col" class="org-left">$ -17.00</th>
    <th scope="col" class="org-left">$ -88.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Cableado</th>
    <th scope="col" class="org-left">fase2:costo:aparato:manoDeObra:cableado</th>
    <th scope="col" class="org-left">$ -1.00</th>
    <th scope="col" class="org-left">$ -89.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Carcasa</th>
    <th scope="col" class="org-left">fase2:costo:aparato:manoDeObra:diseno:carcasa</th>
    <th scope="col" class="org-left">$ -20.00</th>
    <th scope="col" class="org-left">$ -109.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Código backend</th>
    <th scope="col" class="org-left">fase2:costo:aparato:manoDeObra:codigo</th>
    <th scope="col" class="org-left">$ -10.00</th>
    <th scope="col" class="org-left">$ -119.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Análisis-Mapas</th>
    <th scope="col" class="org-left">fase2:costo:servicio:analisis:mapas</th>
    <th scope="col" class="org-left">$ -10.00</th>
    <th scope="col" class="org-left">$ -129.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Aplicación móvil Android</th>
    <th scope="col" class="org-left">fase2:costo:servicio:aplicacion:android</th>
    <th scope="col" class="org-left">$ -10.00</th>
    <th scope="col" class="org-left">$ -139.81</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Lector memoria SD</th>
    <th scope="col" class="org-left">fase2:costo:aparato:componente:lectorSD</th>
    <th scope="col" class="org-left">$ -0.66</th>
    <th scope="col" class="org-left">$ -140.47</th>
    </tr>
    
    
    <tr>
    <th scope="col" class="org-left">Infraestructura</th>
    <th scope="col" class="org-left">fase2:costo:aparato:infraestructura</th>
    <th scope="col" class="org-left">$ -12.00</th>
    <th scope="col" class="org-left">$ -152.47</th>
    </tr>
    </thead>
    
    <tbody>
    <tr>
    <td class="org-left">Impuestos IVA 19%</td>
    <td class="org-left">fase2:costo:aparato:impuestos</td>
    <td class="org-left">$ -28.88</td>
    <td class="org-left">$ -181.35</td>
    </tr>
    
    
    <tr>
    <td class="org-left">Utilidad</td>
    <td class="org-left">fase2:costo:aparato:utilidad</td>
    <td class="org-left">$ -30.40</td>
    <td class="org-left">$ -211.75</td>
    </tr>
    </tbody>
    
    <tbody>
    <tr>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">Total</td>
    <td class="org-left">$ -211.75</td>
    </tr>
    </tbody>
    </table>

