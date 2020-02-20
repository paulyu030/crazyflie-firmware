function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtU"] = {file: "C:\\Dropbox\\ControlLab\\Quadcopter\\matlabworkspace\\crazyflie_low_level_simulink\\thrust_test_ert_rtw\\thrust_test.c",
	size: 4};
	 this.metricsArray.var["rtY"] = {file: "C:\\Dropbox\\ControlLab\\Quadcopter\\matlabworkspace\\crazyflie_low_level_simulink\\thrust_test_ert_rtw\\thrust_test.c",
	size: 8};
	 this.metricsArray.fcn["thrust_test_initialize"] = {file: "C:\\Dropbox\\ControlLab\\Quadcopter\\matlabworkspace\\crazyflie_low_level_simulink\\thrust_test_ert_rtw\\thrust_test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["thrust_test_step"] = {file: "C:\\Dropbox\\ControlLab\\Quadcopter\\matlabworkspace\\crazyflie_low_level_simulink\\thrust_test_ert_rtw\\thrust_test.c",
	stack: 2,
	stackTotal: 2};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="thrust_test_metrics.html">Global Memory: 12(bytes) Maximum Stack: 2(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
