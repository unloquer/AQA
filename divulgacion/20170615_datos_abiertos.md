<div id="table-of-contents">
<h2>&Iacute;ndice</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#orgdcdd48d">¿Qué vamos a aprender hoy?</a>
<ul>
<li><a href="#org70b8c1d">¿Cómo en un/loquer se esta respondiendo ante el problema del aire?</a></li>
<li><a href="#orgc00af6e">¿Qué puedo aprender con los datos que exponen?</a></li>
<li><a href="#org0132063">¿De qué me sirve los aspectos "abiertos" de lo que están haciendo?</a></li>
</ul>
</li>
</ul>
</div>
</div>


<a id="orgdcdd48d"></a>

# ¿Qué vamos a aprender hoy?


<a id="org70b8c1d"></a>

## ¿Cómo en un/loquer se esta respondiendo ante el problema del aire?

-   ¿Artefacto para medir y reportar?

    -   DONE ¿Microcontrolador? (ESP8266)
    
    -   DONE ¿Sensor de partículas?
    
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


<a id="orgc00af6e"></a>

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


<a id="org0132063"></a>

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

