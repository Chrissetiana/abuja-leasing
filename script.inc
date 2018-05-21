<script>
	jQuery(function($) {
		'use strict';
		if ($.fn.slider) {
			$(".css-slidecontainer8b2c34cc85e64992aaddd69bca68111a").each(function () {
				var slideContainer = $(this), tmp;
				var inner = $(".css-slider-inner", slideContainer);
				var helper = null;


				inner.children().eq(0).addClass("active");
				slideContainer.slider({
					pause: 2600,
					speed: 600,
					repeat: true,
					animation: "fade",
					direction: "next",
					navigator: slideContainer.siblings(".css-slidenavigator8b2c34cc85e64992aaddd69bca68111a"),
					helper: helper
								});
			});
		}
	});
</script>