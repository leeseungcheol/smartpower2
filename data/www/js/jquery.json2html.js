/* eslint-disable */
function json2html_events(t){for(var e=$(document.createElement("i")).html(t.html),n=0;n<t.events.length;n++){var o=t.events[n],s=$(e).find("[json2html-event-id-"+o.type+"='"+o.id+"']");if(0===s.length)throw"jquery.json2html was unable to attach event "+o.id+" to DOM";$(s).removeAttr("json2html-event-id-"+o.type),$(s).on(o.type,o.data,function(t){t.data.event=t,t.data.action.call($(this),t.data)})}return $(e).children()}!function(t){t.json2html=function(e,n,o){if("undefined"!=typeof json2html){var s={output:"json2html"};switch(void 0!==o&&t.extend(s,o),s.output){case"json2html":return s.events=!0,json2html.transform(e,n,s);case"html":return s.events=!1,json2html.transform(e,n,s);case"jquery":return s.events=!1,json2html_events(json2html.transform(e,n,s))}}},t.fn.json2html=function(e,n,o){if("undefined"!=typeof json2html){var s={append:!0,replace:!1,prepend:!1,eventData:{}};return void 0!==o&&t.extend(s,o),s.events=!0,this.each(function(){var o=json2html_events(json2html.transform(e,n,s));s.replace?t.fn.replaceWith.call(t(this),o):s.prepend?t.fn.prepend.call(t(this),o):t.fn.append.call(t(this),o)})}}}(jQuery);