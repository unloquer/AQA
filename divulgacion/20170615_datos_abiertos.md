<div id="table-of-contents">
<h2>&Iacute;ndice</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#orgd4ae757">¿Qué vamos a aprender hoy?</a>
<ul>
<li><a href="#org76be75c">¿Cómo en un/loquer se esta respondiendo ante el problema del aire?</a></li>
<li><a href="#org843fc4e">¿Qué puedo aprender con los datos que exponen?</a></li>
<li><a href="#org2be2a97">¿De qué me sirve los aspectos "abiertos" de lo que están haciendo?</a></li>
</ul>
</li>
<li><a href="#org22d54b2">¿Qué vamos a aprender hoy?</a>
<ul>
<li><a href="#org0bbdd6e">¿Cómo en un/loquer se esta respondiendo ante el problema del aire?</a></li>
<li><a href="#org4a3197e">¿Qué puedo aprender con los datos que exponen?</a></li>
<li><a href="#org1357595">¿De qué me sirve los aspectos "abiertos" de lo que están haciendo?</a></li>
</ul>
</li>
</ul>
</div>
</div>


<a id="orgd4ae757"></a>

# ¿Qué vamos a aprender hoy?


<a id="org76be75c"></a>

## ¿Cómo en un/loquer se esta respondiendo ante el problema del aire?

-   ¿Artefacto para medir y reportar?

    Un dispositivo que permite hacer mediciones móviles.
    
    -   DONE ¿Microcontrolador? (ESP8266)
    
        Tiene conectividad wi-fi integrada, recive los datos de direferentes protocolos y genera la trama de datos.
        
        <table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">
        
        
        <colgroup>
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-left" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        </colgroup>
        <tbody>
        <tr>
        <td class="org-right">lat</td>
        <td class="org-right">lng</td>
        <td class="org-left">date</td>
        <td class="org-right">hour</td>
        <td class="org-right">altitude</td>
        <td class="org-right">course</td>
        <td class="org-right">speed</td>
        <td class="org-right">humidity</td>
        <td class="org-right">temperature</td>
        <td class="org-right">pm1</td>
        <td class="org-right">pm25</td>
        <td class="org-right">pm10</td>
        </tr>
        
        
        <tr>
        <td class="org-right">6.254207</td>
        <td class="org-right">-75.575022</td>
        <td class="org-left">5/11/2017</td>
        <td class="org-right">05:54:00.00</td>
        <td class="org-right">1498.5</td>
        <td class="org-right">189.57</td>
        <td class="org-right">14.24</td>
        <td class="org-right">34.0</td>
        <td class="org-right">28.0</td>
        <td class="org-right">11</td>
        <td class="org-right">16</td>
        <td class="org-right">17</td>
        </tr>
        
        
        <tr>
        <td class="org-right">6.253995</td>
        <td class="org-right">-75.575045</td>
        <td class="org-left">5/11/2017</td>
        <td class="org-right">05:54:05.00</td>
        <td class="org-right">1499.1</td>
        <td class="org-right">179.03</td>
        <td class="org-right">15.26</td>
        <td class="org-right">34.0</td>
        <td class="org-right">28.0</td>
        <td class="org-right">11</td>
        <td class="org-right">16</td>
        <td class="org-right">17</td>
        </tr>
        
        
        <tr>
        <td class="org-right">6.253763</td>
        <td class="org-right">-75.575067</td>
        <td class="org-left">5/11/2017</td>
        <td class="org-right">05:54:11.00</td>
        <td class="org-right">1498.8</td>
        <td class="org-right">186.22</td>
        <td class="org-right">14.46</td>
        <td class="org-right">34.0</td>
        <td class="org-right">28.0</td>
        <td class="org-right">11</td>
        <td class="org-right">16</td>
        <td class="org-right">17</td>
        </tr>
        
        
        <tr>
        <td class="org-right">6.253593</td>
        <td class="org-right">-75.575132</td>
        <td class="org-left">5/11/2017</td>
        <td class="org-right">05:54:16.00</td>
        <td class="org-right">1497.9</td>
        <td class="org-right">215.65</td>
        <td class="org-right">12.45</td>
        <td class="org-right">34.0</td>
        <td class="org-right">28.0</td>
        <td class="org-right">11</td>
        <td class="org-right">16</td>
        <td class="org-right">17</td>
        </tr>
        
        
        <tr>
        <td class="org-right">6.253485</td>
        <td class="org-right">-75.575307</td>
        <td class="org-left">5/11/2017</td>
        <td class="org-right">05:54:22.00</td>
        <td class="org-right">1498.3</td>
        <td class="org-right">256.68</td>
        <td class="org-right">14.41</td>
        <td class="org-right">34.0</td>
        <td class="org-right">28.0</td>
        <td class="org-right">11</td>
        <td class="org-right">16</td>
        <td class="org-right">17</td>
        </tr>
        
        
        <tr>
        <td class="org-right">6.253502</td>
        <td class="org-right">-75.575495</td>
        <td class="org-left">5/11/2017</td>
        <td class="org-right">05:54:27.00</td>
        <td class="org-right">1498.2</td>
        <td class="org-right">296.0</td>
        <td class="org-right">14.89</td>
        <td class="org-right">34.0</td>
        <td class="org-right">28.0</td>
        <td class="org-right">11</td>
        <td class="org-right">16</td>
        <td class="org-right">17</td>
        </tr>
        </tbody>
        </table>
        
        -   ¿Almacena los datos?
        
            Sí, porque no podemos garantizar conectividad wi-fi, se está trabajando en implementar el reporte a travéz de una red LoRa
    
    -   GPS
    
        Entrega Latitud, Longitud, Altitud, Curso, y Velocidad, ver issue <https://github.com/unloquer/AQA/issues/18>
    
    -   DONE ¿Sensor de partículas?
    
        Entrega mediciones de partículas pm1, pm2.5 y pm10.
    
    -   ¿Sensor de temperatura y humedad? DHT11
    
    -   ¿RGB Leds?
    
        Retroalimentación visual expresada en colores ajustada a alguna escala.
    
    -   TODO ¿Carcasa?
    
    -   ¿Compartir los datos capturados?
    
        -   DONE ¿Prueba de concepto?
        
            Actualmente los datos se descargan de la memoria Flash de forma rudimentaria.
        
        -   TODO ¿Descarga con Wi-Fi?
        
            Requiere un navegador para conectar el ESP a alguna red disponible.
        
        -   TODO ¿LoRa?
        
            Estamos en la búsqueda de unos gateway para hacer una prueba de concepto.

-   Detonantes:

    -   Cuanto le vale a la ciudad darle información al individuo de su entorno vs. Cuanto le vale al individo generar esa info
    
    -   ¿Aprendizaje a travez de problemas? **\*** ¿aprender? ¿en serio?
    
        -   anarquía; no reconoce autoridad, paternalismo, ¿Qué hacemos?
        
        -   varias ligas     :Fix:
        
            -   escala ciudad
            
            -   escala personal


<a id="org843fc4e"></a>

## ¿Qué puedo aprender con los datos que exponen?

-   dataPoints (advertencia!)  <https://raw.githubusercontent.com/daquina-io/VizCalidadAire/master/data/points.csv>

    -   ¿Porqué hay una medida de 500 !!! ¿subjetiva?
    
        Son datos sucios por diferentes razones, algunas ideas de depuración de @kleper <https://github.com/daquina-io/VizCalidadAire/issues/2>
        
        -   ¿Cómo podemos calibrar? <https://github.com/unloquer/AQA/issues/13>
        
        -   Link a mediciones mayores a 100 <http://daquina.io/aqaviz/?_inputs_&dates=%5B%222017-03-01%22%2C%222017-10-11%22%5D&map_bounds=%7B%22north%22%3A6.38627143781799%2C%22east%22%3A-75.340461730957%2C%22south%22%3A6.11939048057678%2C%22west%22%3A-75.8781051635742%7D&map_zoom=12&range=%5B103%2C187%5D&undefined_shape_click=%7B%22id%22%3Anull%2C%22.nonce%22%3A0.468528855641437%2C%22lat%22%3A6.182392%2C%22lng%22%3A-75.550095%7D&undefined_shape_mouseout=%7B%22id%22%3Anull%2C%22.nonce%22%3A0.631095207384145%2C%22lat%22%3A6.18352%2C%22lng%22%3A-75.547245%7D&undefined_shape_mouseover=%7B%22id%22%3Anull%2C%22.nonce%22%3A0.697734141732581%2C%22lat%22%3A6.18352%2C%22lng%22%3A-75.547245%7D&wday=%5B%22Sunday%22%2C%22Monday%22%2C%22Tuesday%22%2C%22Wednesday%22%2C%22Thursday%22%2C%22Friday%22%2C%22Saturday%22%5D>
        
        -   ¿Y si le agregamos un consenso?
        
            Tener muchas mediciones del mismo sitio en diferentes días y horas permitiría ir validando los datos.
        
        -   Gps
        
            Emite datos errados cuando se está localizando, el asunto se esta tratando acá: <https://github.com/unloquer/AQA/issues/18>

-   Detonantes

    -   ¿Puedo hacer mi propia comunidad de aire?
    
        -   ¿Porque comunidades pequeñas?
    
    -   ¿Puedo poner historias ?


<a id="org2be2a97"></a>

## ¿De qué me sirve los aspectos "abiertos" de lo que están haciendo?

-   ¿Respecto al Firmware?

    -   ¿Puedo adaptar el código a mis necesidades?
    
    -   ¿Puedo quitar o agregar componentes (micrófono)?

-   ¿Respecto al Hardware?     :Check:

    -   ¿Puedo cambiar el diseño PCB? ¿Para qué?
    
    -   ¿Diseño sensor?     :Check:
    
    -   ¿Microcontrolador ESP2688?     :Check:

-   ¿Se puede alterar los datos?

    -   ¿blame? ¿cadena de custodia? ¿blockchain?

-   ¿Porqué publican el presupuesto? <https://github.com/unloquer/AQA/blob/master/costos.dat>

    <table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">
    
    
    <colgroup>
    <col  class="org-left" />
    
    <col  class="org-right" />
    
    <col  class="org-right" />
    </colgroup>
    <thead>
    <tr>
    <th scope="col" class="org-left">muñeco</th>
    <th scope="col" class="org-right">us$</th>
    <th scope="col" class="org-right">col$</th>
    </tr>
    </thead>
    
    <tbody>
    <tr>
    <td class="org-left">diy</td>
    <td class="org-right">44</td>
    <td class="org-right">128876</td>
    </tr>
    
    
    <tr>
    <td class="org-left">muñeco</td>
    <td class="org-right">108</td>
    <td class="org-right">316332</td>
    </tr>
    
    
    <tr>
    <td class="org-left">embebido y red fácil</td>
    <td class="org-right">178</td>
    <td class="org-right">521362</td>
    </tr>
    </tbody>
    </table>

-   Documentacion

    -   Repositorio  <https://github.com/unloquer/AQA>
    
        -   Fork
        
        -   Clone
        
        -   Pull request
        
        -   Blame
    
    -   Wiki <http://wiki.unloquer.org/personas/brolin/proyectos/agentes_calidad_aire>

-   Asuntos / issues / problemas <https://github.com/unloquer/AQA/issues>

-   ¿ lo puedo cerrar y vender?

    -   ¿licenciar para mantener abierto?
    
        -   ¿TAPR?  <http://www.tapr.org/OHL>

-   Detonantes

    -   ¿Para que dure más de 100 años debe ser abierto o cerrado?


<a id="org22d54b2"></a>

# ¿Qué vamos a aprender hoy?


<a id="org0bbdd6e"></a>

## ¿Cómo en un/loquer se esta respondiendo ante el problema del aire?

-   ¿Artefacto para medir y reportar?

    Un dispositivo que permite hacer mediciones moviles.
    
    -   DONE ¿Microcontrolador? (ESP8266)
    
        Tiene conectividad wi-fi integrada, recive los datos de direferentes protocolos y genera la trama de datos.
        
        <table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">
        
        
        <colgroup>
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-left" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        
        <col  class="org-right" />
        </colgroup>
        <tbody>
        <tr>
        <td class="org-right">lat</td>
        <td class="org-right">lng</td>
        <td class="org-left">date</td>
        <td class="org-right">hour</td>
        <td class="org-right">altitude</td>
        <td class="org-right">course</td>
        <td class="org-right">speed</td>
        <td class="org-right">humidity</td>
        <td class="org-right">temperature</td>
        <td class="org-right">pm1</td>
        <td class="org-right">pm25</td>
        <td class="org-right">pm10</td>
        </tr>
        
        
        <tr>
        <td class="org-right">6.254207</td>
        <td class="org-right">-75.575022</td>
        <td class="org-left">5/11/2017</td>
        <td class="org-right">05:54:00.00</td>
        <td class="org-right">1498.5</td>
        <td class="org-right">189.57</td>
        <td class="org-right">14.24</td>
        <td class="org-right">34.0</td>
        <td class="org-right">28.0</td>
        <td class="org-right">11</td>
        <td class="org-right">16</td>
        <td class="org-right">17</td>
        </tr>
        
        
        <tr>
        <td class="org-right">6.253995</td>
        <td class="org-right">-75.575045</td>
        <td class="org-left">5/11/2017</td>
        <td class="org-right">05:54:05.00</td>
        <td class="org-right">1499.1</td>
        <td class="org-right">179.03</td>
        <td class="org-right">15.26</td>
        <td class="org-right">34.0</td>
        <td class="org-right">28.0</td>
        <td class="org-right">11</td>
        <td class="org-right">16</td>
        <td class="org-right">17</td>
        </tr>
        
        
        <tr>
        <td class="org-right">6.253763</td>
        <td class="org-right">-75.575067</td>
        <td class="org-left">5/11/2017</td>
        <td class="org-right">05:54:11.00</td>
        <td class="org-right">1498.8</td>
        <td class="org-right">186.22</td>
        <td class="org-right">14.46</td>
        <td class="org-right">34.0</td>
        <td class="org-right">28.0</td>
        <td class="org-right">11</td>
        <td class="org-right">16</td>
        <td class="org-right">17</td>
        </tr>
        
        
        <tr>
        <td class="org-right">6.253593</td>
        <td class="org-right">-75.575132</td>
        <td class="org-left">5/11/2017</td>
        <td class="org-right">05:54:16.00</td>
        <td class="org-right">1497.9</td>
        <td class="org-right">215.65</td>
        <td class="org-right">12.45</td>
        <td class="org-right">34.0</td>
        <td class="org-right">28.0</td>
        <td class="org-right">11</td>
        <td class="org-right">16</td>
        <td class="org-right">17</td>
        </tr>
        
        
        <tr>
        <td class="org-right">6.253485</td>
        <td class="org-right">-75.575307</td>
        <td class="org-left">5/11/2017</td>
        <td class="org-right">05:54:22.00</td>
        <td class="org-right">1498.3</td>
        <td class="org-right">256.68</td>
        <td class="org-right">14.41</td>
        <td class="org-right">34.0</td>
        <td class="org-right">28.0</td>
        <td class="org-right">11</td>
        <td class="org-right">16</td>
        <td class="org-right">17</td>
        </tr>
        
        
        <tr>
        <td class="org-right">6.253502</td>
        <td class="org-right">-75.575495</td>
        <td class="org-left">5/11/2017</td>
        <td class="org-right">05:54:27.00</td>
        <td class="org-right">1498.2</td>
        <td class="org-right">296.0</td>
        <td class="org-right">14.89</td>
        <td class="org-right">34.0</td>
        <td class="org-right">28.0</td>
        <td class="org-right">11</td>
        <td class="org-right">16</td>
        <td class="org-right">17</td>
        </tr>
        </tbody>
        </table>
        
        -   ¿Almacena los datos?
        
            Sí, porque no podemos garantizar conectividad wi-fi.
    
    -   GPS
    
        Entrega Latitud Longitud
    
    -   DONE ¿Sensor de partículas?
    
        Entrega mediciones de partículas pm1, pm2.5 y pm10.
    
    -   ¿Sensor de temperatura y humedad? DHT11
    
    -   ¿RGB Leds?
    
        Retroalimentación visual expresada en colores ajustada a alguna escala.
    
    -   TODO ¿Carcasa?
    
    -   ¿Compartir los datos capturados?
    
        -   DONE ¿Prueba de concepto?
        
        -   TODO ¿Descarga con Wi-Fi?
        
        -   TODO ¿LoRa?

-   Detonantes:

    -   Cuanto le vale a la ciudad darle información al individuo de su entorno vs. Cuanto le vale al individo generar esa info
    
    -   ¿Aprendizaje a travez de problemas? **\*** ¿aprender? ¿en serio?
    
        -   anarquía; no reconoce autoridad, paternalismo, ¿Qué hacemos?
        
        -   varias ligas     :Fix:
        
            -   escala ciudad
            
            -   escala personal


<a id="org4a3197e"></a>

## ¿Qué puedo aprender con los datos que exponen?

-   dataPoints (advertencia!)  <https://raw.githubusercontent.com/daquina-io/VizCalidadAire/master/data/points.csv>

    -   ¿Porqué hay una medida de 500 !!! ¿subjetiva?
    
        -   ¿Cómo podemos calibrar? <https://github.com/unloquer/AQA/issues/13>
        
        -   Link a mediciones mayores a 100 <http://daquina.io/aqaviz/?_inputs_&dates=%5B%222017-03-01%22%2C%222017-10-11%22%5D&map_bounds=%7B%22north%22%3A6.38627143781799%2C%22east%22%3A-75.340461730957%2C%22south%22%3A6.11939048057678%2C%22west%22%3A-75.8781051635742%7D&map_zoom=12&range=%5B103%2C187%5D&undefined_shape_click=%7B%22id%22%3Anull%2C%22.nonce%22%3A0.468528855641437%2C%22lat%22%3A6.182392%2C%22lng%22%3A-75.550095%7D&undefined_shape_mouseout=%7B%22id%22%3Anull%2C%22.nonce%22%3A0.631095207384145%2C%22lat%22%3A6.18352%2C%22lng%22%3A-75.547245%7D&undefined_shape_mouseover=%7B%22id%22%3Anull%2C%22.nonce%22%3A0.697734141732581%2C%22lat%22%3A6.18352%2C%22lng%22%3A-75.547245%7D&wday=%5B%22Sunday%22%2C%22Monday%22%2C%22Tuesday%22%2C%22Wednesday%22%2C%22Thursday%22%2C%22Friday%22%2C%22Saturday%22%5D>
        
        -   ¿Y si le agregamos un consenso?
        
        -   Invalid
        
        -   Gps
        
        -   Voltaje

-   Detonantes

    -   ¿Puedo hacer mi propia comunidad de aire?
    
        -   ¿Porque comunidades pequeñas?
    
    -   ¿Puedo poner historias ?


<a id="org1357595"></a>

## ¿De qué me sirve los aspectos "abiertos" de lo que están haciendo?

-   ¿Respecto al Firmware?

    -   ¿Puedo adaptar el código a mis necesidades?
    
    -   ¿Puedo quitar o agregar componentes (micrófono)?

-   ¿Respecto al Hardware?     :Check:

    -   ¿Puedo cambiar el diseño PCB? ¿Para qué?
    
    -   ¿Diseño sensor?     :Check:
    
    -   ¿Microcontrolador ESP2688?     :Check:

-   ¿Se puede alterar los datos?

    -   ¿blame? ¿cadena de custodia? ¿blockchain?

-   ¿Porqué publican el presupuesto? <https://github.com/unloquer/AQA/blob/master/costos.dat>

    <table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">
    
    
    <colgroup>
    <col  class="org-left" />
    
    <col  class="org-right" />
    
    <col  class="org-right" />
    </colgroup>
    <thead>
    <tr>
    <th scope="col" class="org-left">muñeco</th>
    <th scope="col" class="org-right">us$</th>
    <th scope="col" class="org-right">col$</th>
    </tr>
    </thead>
    
    <tbody>
    <tr>
    <td class="org-left">diy</td>
    <td class="org-right">44</td>
    <td class="org-right">128876</td>
    </tr>
    
    
    <tr>
    <td class="org-left">muñeco</td>
    <td class="org-right">108</td>
    <td class="org-right">316332</td>
    </tr>
    
    
    <tr>
    <td class="org-left">embebido y red fácil</td>
    <td class="org-right">178</td>
    <td class="org-right">521362</td>
    </tr>
    </tbody>
    </table>

-   Documentacion

    -   Repositorio  <https://github.com/unloquer/AQA>
    
        -   Fork
        
        -   Clone
        
        -   Pull request
        
        -   Blame
    
    -   Wiki <http://wiki.unloquer.org/personas/brolin/proyectos/agentes_calidad_aire>

-   Asuntos / issues / problemas <https://github.com/unloquer/AQA/issues>

-   ¿ lo puedo cerrar y vender?

    -   ¿licenciar para mantener abierto?
    
        -   ¿TAPR?  <http://www.tapr.org/OHL>

-   Detonantes

    -   ¿Para que dure más de 100 años debe ser abierto o cerrado?

