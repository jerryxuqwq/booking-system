.PHONY: clean All

All:
	@echo "----------Building project:[ BookingSystem - Release ]----------"
	@"$(MAKE)" -f  "BookingSystem.mk"
clean:
	@echo "----------Cleaning project:[ BookingSystem - Release ]----------"
	@"$(MAKE)" -f  "BookingSystem.mk" clean
