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

Medellín tiene un problema de calidad del aire, la política pública tiene planes a largo plazo, el sistema publico de monitoreo de calidad del aire tiene alcance limitado. 


<a id="org3b60fa9"></a>

## Problema

El ciudadano no tiene una medición del aire que respira en el momento. 


<a id="orge3aaf79"></a>

## Solución propuesta

Medidor portable que indique visualmente la calidad del aire y que permita socializar esas mediciones.


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

