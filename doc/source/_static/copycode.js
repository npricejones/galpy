var copyCode = {
  init: function() {
    $('.highlight pre').each(function() {
      var code = $(this);
      code.after('<span class="copy-to-clipboard"><img class="clippy" width="13" src="_static/clippy.svg" title="Copy to clipboard"></span>');
      code.on('mouseenter', function() {
        var copyBlock = $(this).next('.copy-to-clipboard');
        copyBlock.addClass('copy-active');
	copyBlock.html('<img class="clippy" width="13" src="_static/clippy.svg" title="Copy to clipboard">');
      });
      code.on('mouseleave', function(e) {
        var copyBlock = $(this).next('.copy-to-clipboard');
        copyBlock.removeClass('copy-active');
	copyBlock.html('<img class="clippy" width="13" src="_static/clippy.svg" title="Copy to clipboard">');
	      });
    });
    var text, clip = new Clipboard('.copy-to-clipboard', {
        text: function(trigger) {
          return $(trigger).prev('pre').text();
        }
      });

      clip.on('success', function(e) {
        e.clearSelection();
        console.log("Copied!");
        $(e.trigger).html("Copied!");
      });

      clip.on('error', function(e) {
        console.log("error: " + e);
      });
  },
};

$(document).ready(copyCode.init);
