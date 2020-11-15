.PHONY: clean All

All:
	@echo "----------Building project:[ BookingSystem - Debug ]----------"
	@"$(MAKE)" -f  "BookingSystem.mk"
clean:
	@echo "----------Cleaning project:[ BookingSystem - Debug ]----------"
	@"$(MAKE)" -f  "BookingSystem.mk" clean
