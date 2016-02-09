<a id="github-original-css" href="javascript:console.log(9);">Here</a>
<script>
    console.log("Loaded");
    $(document).ready(
        function() {
            var url = $('link[rel=stylesheet]').attr('href');
            $('#github-original-css').attr('href') = url;
            console.log(url);
        }
    );
</script>
