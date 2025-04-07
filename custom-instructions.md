# Custom Instructions

## Development Guidelines

### Arduino Code Style
- Use clear, descriptive variable names
- Add comments for complex logic, avoid overcommenting
- Keep functions small and focused
- Use consistent indentation (4 spaces)
- Define constants for pin numbers at the top of the file in UPPER_CASE

### Version Control
- Make atomic commits with clear messages
- Update CHANGELOG.md for notable changes
- Follow semantic versioning (MAJOR.MINOR.PATCH)

### Hardware Configuration
- Document any changes to pin assignments
- Update wiring diagrams when modifying hardware setup
- Test all connections before powering on
- Use appropriate resistors for button inputs

### Testing
- Manual Testing Procedures:
  - Test each button individually using Serial Monitor output
  - Verify motor movements one direction at a time
  - Test complete movement sequences with simple patterns
  - Validate Clear/Start button functionality
  - Document any unexpected behaviors
- Hardware Testing:
  - Check voltage levels at test points
  - Verify motor rotation directions
  - Test emergency stop functionality
- Quality Checks:
  - Movement accuracy (straight lines, 90-degree turns)
  - Button responsiveness
  - Battery life duration

### Safety
- Always disconnect power before making changes
- Ensure proper wire insulation
- Keep working area clear of conductive materials
- Monitor motor temperature during extended use

## Operation Instructions
1. Power on checks:
   - Verify battery connection
   - Check all buttons respond correctly
   - Ensure motors are properly mounted

2. Programming sequence:
   - Press buttons in desired movement order
   - Use Clear to reset if needed
   - Press Start to execute commands

3. Maintenance:
   - Clean wheels regularly
   - Check for loose connections
   - Replace batteries when voltage drops
   - Inspect wiring monthly