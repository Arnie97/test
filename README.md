<a id="github-original-css" href="javascript:console.log("inline");">Here</a>
<script>
    console.log("tag");
    $(document).ready(
        function() {
            var url = $('link[rel=stylesheet]').attr('href');
            $('#github-original-css').attr('href') = url;
            console.log(url);
        }
    );
</script>

 文件  | 函数   | 描述
-------|--------|--------------
 mul.c | mul    | 硬件指令乘法
       | mul_t1 | 原码一位乘法
       | mul_c1 | 补码一位乘法
