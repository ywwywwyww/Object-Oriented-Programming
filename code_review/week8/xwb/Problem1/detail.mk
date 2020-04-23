##
# by Kirin (1370302499@qq.com)
# version 0.5
#
# Copyright (c) 2020 Kirin
##


##### detail #####

$(dependencies): $(BUILD)/%.d: $(SOURCE)/%.cpp
	@echo [33mParsing dependency of [1m$(<F)[0m[33m ...[0m
	$(COMPILER) -I$(INCLUDE) -MM $< -MT"$@ $(patsubst %.d,%.o,$@)" -MF $@
include $(dependencies)
$(objects):
	@echo [33mCompiling [1m$(<F)[0m[33m ...[0m
	$(COMPILER) $(FLAGS) -I$(INCLUDE) -c $< -o $@
$(executable): $(objects)
	@echo [33mGenerating [1m$(TARGET)[0m[33m ...[0m
	$(COMPILER) $^ -o $@
