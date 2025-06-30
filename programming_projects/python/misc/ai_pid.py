class PIDController:
    def __init__(self, Kp, Ki, Kd):
        self.Kp = Kp
        self.Ki = Ki
        self.Kd = Kd
        self.prev_error = 0
        self.integral = 0

    def compute(self, setpoint, pv, dt):
        error = setpoint - pv
        self.integral += error * dt
        derivative = (error - self.prev_error) / dt
        output = self.Kp * error + self.Ki * self.integral + self.Kd * derivative
        self.prev_error = error
        return output

# Example usage
pid = PIDController(Kp=0.1, Ki=0.01, Kd=0.05)
setpoint = 1000  # Desired speed
pv = 900  # Current speed (process variable)
dt = 0.1  # Time step
control_output = pid.compute(setpoint, pv, dt)
