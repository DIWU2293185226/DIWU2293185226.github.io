$(function(){
	$.ajax({
		type:"get",
		url:"./README.md",
		dataType:"html",
		success:function(res){
		$("#content").append(marked(res));  // 使用marked插件解析.md文件
		}
	})
})