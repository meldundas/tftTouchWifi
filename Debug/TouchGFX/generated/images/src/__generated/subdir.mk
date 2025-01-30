################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_rounded_tiny_outline_active.cpp \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_rounded_tiny_outline_pressed.cpp \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_off.cpp \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_off_pressed.cpp \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_on_dark.cpp \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_on_pressed.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_navigation_cancel_50_50_E8F6FB.svg.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_notification_wifi_50_50_000000.svg.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_notification_wifi_50_50_04CF95.svg.cpp 

OBJS += \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_rounded_tiny_outline_active.o \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_rounded_tiny_outline_pressed.o \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_off.o \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_off_pressed.o \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_on_dark.o \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_on_pressed.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_navigation_cancel_50_50_E8F6FB.svg.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_notification_wifi_50_50_000000.svg.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_notification_wifi_50_50_04CF95.svg.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_rounded_tiny_outline_active.d \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_rounded_tiny_outline_pressed.d \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_off.d \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_off_pressed.d \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_on_dark.d \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_on_pressed.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_navigation_cancel_50_50_E8F6FB.svg.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_notification_wifi_50_50_000000.svg.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_notification_wifi_50_50_04CF95.svg.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/__generated/%.o TouchGFX/generated/images/src/__generated/%.su TouchGFX/generated/images/src/__generated/%.cyclo: ../TouchGFX/generated/images/src/__generated/%.cpp TouchGFX/generated/images/src/__generated/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated:
	-$(RM) ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_rounded_tiny_outline_active.cyclo ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_rounded_tiny_outline_active.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_rounded_tiny_outline_active.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_rounded_tiny_outline_active.su ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_rounded_tiny_outline_pressed.cyclo ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_rounded_tiny_outline_pressed.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_rounded_tiny_outline_pressed.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_rounded_tiny_outline_pressed.su ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_off.cyclo ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_off.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_off.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_off.su ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_off_pressed.cyclo ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_off_pressed.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_off_pressed.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_off_pressed.su ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_on_dark.cyclo ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_on_dark.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_on_dark.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_on_dark.su ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_on_pressed.cyclo ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_on_pressed.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_on_pressed.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_radiobutton_radio_medium_rounded_on_pressed.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_navigation_cancel_50_50_E8F6FB.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_navigation_cancel_50_50_E8F6FB.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_navigation_cancel_50_50_E8F6FB.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_navigation_cancel_50_50_E8F6FB.svg.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_notification_wifi_50_50_000000.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_notification_wifi_50_50_000000.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_notification_wifi_50_50_000000.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_notification_wifi_50_50_000000.svg.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_notification_wifi_50_50_04CF95.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_notification_wifi_50_50_04CF95.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_notification_wifi_50_50_04CF95.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_notification_wifi_50_50_04CF95.svg.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated

