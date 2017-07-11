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

Medellín tiene un problema de calidad del aire, la política pública tiene planes a largo plazo, el sistema publico de monitoreo de calidad del aire tiene alcance limitado. 


<a id="orge21955c"></a>

## Problema

El ciudadano no tiene una medición del aire que respira en el momento. 


<a id="orgf99aaa4"></a>

## Solución propuesta

Medidor portable que indique visualmente la calidad del aire y que permita socializar esas mediciones.


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

